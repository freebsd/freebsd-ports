# Created by: clive@FreeBSD.org
# $FreeBSD$

PORTNAME=	DBD-ODBC
PORTVERSION=	1.43
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

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	ODBC
OPTIONS_SINGLE_ODBC=	IODBC UNIXODBC
OPTIONS_DEFAULT=	ODBC IODBC

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-o ${LOCALBASE}

PORTDOCS=	Changes README README.adabas README.informix

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MODBC)
IGNORE=		an ODBC driver (iODBC or unixODBC) is required
.endif

.if ${PORT_OPTIONS:MIODBC}
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
MYODBC=		iodbc
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
MYODBC=		unixodbc
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/my $$myodbc/ s|q{}|"${MYODBC}"|' ${WRKSRC}/Makefile.PL

post-configure:
.if ${PORT_OPTIONS:MUNIXODBC}
	@${PERL} -pi -e 's/-lodbc/-lodbc ${PTHREAD_LIBS}/g;' \
		-e 's/$$/ ${PTHREAD_CFLAGS}/ if (/^CCFLAGS/);' \
		${WRKSRC}/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
