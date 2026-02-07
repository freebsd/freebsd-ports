PORTNAME=	znc-clientbuffer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.48
PORTREVISION=	2
CATEGORIES=	irc

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Client specific buffers module for ZNC
WWW=		https://wiki.znc.in/Clientbuffer

LICENSE=	APACHE20

BUILD_DEPENDS=	znc:irc/znc
RUN_DEPENDS=	znc:irc/znc

USE_GITHUB=	yes
GH_ACCOUNT=	CyberShadow

ALL_TARGET=	clientbuffer.so

PORTSCOUT=	skipv:znc-1.6.0

PLIST_FILES=	lib/znc/clientbuffer.so

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/znc
	${INSTALL_PROGRAM} ${WRKSRC}/clientbuffer.so ${STAGEDIR}${PREFIX}/lib/znc/clientbuffer.so

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
