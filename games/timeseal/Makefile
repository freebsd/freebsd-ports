# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	timeseal
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort
DISTFILES=	timeseal.BSD386-1.0-i386
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Account for network lag in FICS chess games

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
STRIP=		# strip(1) does not support a.out binaries
PLIST_FILES=	bin/timeseal
PKGMESSAGE=	pkg-message.aout

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/${_DISTFILES} ${STAGEDIR}${PREFIX}/bin/timeseal

.include <bsd.port.mk>
