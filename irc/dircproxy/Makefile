# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	dircproxy
DISTVERSION=	1.2.0-RC1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://dircproxy.googlecode.com/files/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Detachable irc proxy server with many features

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable (google code has gone away)

GNU_CONFIGURE=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.mk>
