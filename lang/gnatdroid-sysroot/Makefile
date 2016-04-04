# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysroot
PORTVERSION=	23
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/gnatdroid/
PKGNAMEPREFIX=	gnatdroid-
DISTNAME=	android-${API}-arm
DIST_SUBDIR=	gnatdroid-ndk11

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Android sysroots for C/Ada Android cross-compiler

ONLY_FOR_ARCHS=	i386 amd64

USES=		tar:bzip2
NO_BUILD=	yes
NO_MTREE=	yes

WRKSRC=		${WRKDIR}/android-${API}-arm
PREFIX=		${LOCALBASE}/android
STAT_PATCH=	${FILESDIR}/extra-stat.h
EXTRA_PATCHES=	${STAT_PATCH}

OPTIONS_SINGLE=		SG1
OPTIONS_SINGLE_SG1=	ICS JBEAN16 JBEAN17 JBEAN18 KITKAT LOLLIPOP MARSH
OPTIONS_DEFAULT=	KITKAT

ICS_DESC=	Android 4.0 - API level 15 - Ice Cream Sandwich 2
JBEAN16_DESC=	Android 4.1 - API level 16 - Jelly Bean 1
JBEAN17_DESC=	Android 4.2 - API level 17 - Jelly Bean 2
JBEAN18_DESC=	Android 4.3 - API level 18 - Jelly Bean 3
KITKAT_DESC=	Android 4.4 - API level 19 - Kitkat
LOLLIPOP_DESC=	Android 5.0 - API level 21 - Lollipop
MARSH_DESC=	Android 6.0 - API Level 23 - Marshmellow

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICS}
API=	15
.elif ${PORT_OPTIONS:MJBEAN16}
API=	16
.elif ${PORT_OPTIONS:MJBEAN17}
API=	17
.elif ${PORT_OPTIONS:MJBEAN18}
API=	18
.elif ${PORT_OPTIONS:MKITKAT}
API=	19
.elif ${PORT_OPTIONS:MLOLLIPOP}
API=	21
STAT_PATCH=	${FILESDIR}/extra-21-stat.h
.elif ${PORT_OPTIONS:MMARSH}
API=	23
STAT_PATCH=	${FILESDIR}/extra-21-stat.h
.else
IGNORE=	the API option is improperly selected
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} usr ${STAGEDIR}${PREFIX})

post-install:
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} usr \( -type f -or -type l \) | \
		${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
