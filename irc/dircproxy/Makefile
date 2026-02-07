PORTNAME=	dircproxy
DISTVERSION=	1.2.0-RC1
PORTREVISION=	3
CATEGORIES=	irc

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Detachable irc proxy server with many features
WWW=		https://github.com/w8tvi/dircproxy

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	w8tvi
GH_PROJECT=	dircproxy
GH_TAGNAME=	dc563b3

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
SUB_FILES+=	pkg-message
USES=		autoreconf cpe

post-install:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
