# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysroot
PORTVERSION=	23
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/gnatdroid/
PKGNAMEPREFIX=	gnatdroid-
PKGNAMESUFFIX=	-x86
DISTNAME=	android-${API}-x86
DIST_SUBDIR=	gnatdroid-ndk11

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Android sysroots for C/Ada Android cross-compiler (x86)

ONLY_FOR_ARCHS=	i386 amd64

USES=		tar:bzip2
NO_BUILD=	yes
NO_MTREE=	yes

PREFIX=		${LOCALBASE}/android-x86
STAT_PATCH=	${FILESDIR}/extra-stat.h
EXTRA_PATCHES=	${STAT_PATCH}

OPTIONS_SINGLE=		SG1
OPTIONS_SINGLE_SG1=	KITKAT LOLLIPOP MARSH
OPTIONS_DEFAULT=	KITKAT

KITKAT_DESC=	Android 4.4 - API level 19 - Kitkat
LOLLIPOP_DESC=	Android 5.0 - API level 21 - Lollipop
MARSH_DESC=	Android 6.0 - API Level 23 - Marshmellow

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKITKAT}
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
