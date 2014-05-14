# Created by: clive@FreeBSD.org
# $FreeBSD$

PORTNAME=	DBD-ODBC
PORTVERSION=	1.45
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MJEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBD module interfacing the ODBC databases

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.609:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-o ${LOCALBASE}

PORTDOCS=	Changes README README.adabas README.informix

MYODBC=		unixodbc

post-patch:
	@${REINPLACE_CMD} -e '/my $$myodbc/ s|q{}|"${MYODBC}"|' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -pi -e 's/-lodbc/-lodbc ${PTHREAD_LIBS}/g;' \
		-e 's/$$/ ${PTHREAD_CFLAGS}/ if (/^CCFLAGS/);' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
