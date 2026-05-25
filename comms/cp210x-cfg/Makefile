PORTNAME=	cp210x-cfg
DISTVERSION=	g20190627
CATEGORIES=	comms

MAINTAINER=	bugs-freebsd-org916@ketas.si.pri.ee
COMMENT=	CLI utility for programming CP210x USB<->UART bridges
WWW=		https://github.com/emaste/cp210x-cfg

LICENSE=	BSD3CLAUSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	emaste
GH_TAGNAME=	055d2dc1b88a92396aad39f81219be93853ab234

ALL_TARGET=	cp210x-cfg

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
