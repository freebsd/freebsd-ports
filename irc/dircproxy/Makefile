# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	dircproxy
DISTVERSION=	1.2.0-RC1
PORTREVISION=	2
CATEGORIES=	irc

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Detachable irc proxy server with many features

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	w8tvi
GH_PROJECT=	dircproxy
GH_TAGNAME=	dc563b3

GNU_CONFIGURE=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USES=		autoreconf

post-install:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
