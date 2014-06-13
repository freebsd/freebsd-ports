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

GNU_CONFIGURE=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
MAN1=		dircproxy.1 dircproxy-crypt.1

post-install:
	@cd ${WRKSRC}/doc && make install-man DESTDIR=${STAGEDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
