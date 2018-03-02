# Created by: clive@FreeBSD.org
# $FreeBSD$

PORTNAME=	DBD-ODBC
PORTVERSION=	1.57
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBD module interfacing the ODBC databases

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.609:databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-o ${LOCALBASE}

PORTDOCS=	Changes README README.adabas README.informix

post-patch:
	@${REINPLACE_CMD} -e '/my $$myodbc/ s|q{}|"unixodbc"|' ${WRKSRC}/Makefile.PL

post-configure:
	@${REINPLACE_CMD} -e 's|-lodbc|& -pthread|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/ODBC/ODBC.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
