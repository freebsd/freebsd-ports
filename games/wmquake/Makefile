# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	wmquake
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Id Software\'s Quake I in a 64x64 WM dockapp window

USES=		gmake tar:bzip2
USE_GNOME=	gtk12

PLIST_FILES=	bin/wmquake

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -fno-strength-reduce
.endif

NO_STAGE=	yes
pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable aggressive optimizations"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmquake ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
