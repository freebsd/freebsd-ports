# New ports collection makefile for:	timeseal
# Date created:				21 Feb 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timeseal
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://ftp3.ru.freebsd.org/.3/games/freechess/timeseal/ \
		ftp://ftp3.ru.freebsd.org/.3/games/freechess/timeseal/
DISTFILES=	timeseal.BSD386-1.0-i386
EXTRACT_ONLY=

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Account for network lag in FICS chess games

NO_BUILD=	yes
STRIP=		# strip(1) does not support a.out binaries
PLIST_FILES=	bin/timeseal

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
PKGMESSAGE=	pkg-message.aout
.endif

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/${_DISTFILES} ${PREFIX}/bin/timeseal

.if defined(PKGMESSAGE)
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
