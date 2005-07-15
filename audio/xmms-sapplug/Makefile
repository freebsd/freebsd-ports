# New ports collection makefile for:	xmms-sapplug
# Date created:				14 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xmms-sapplug
DISTVERSION=	0.3f
CATEGORIES=	audio
MASTER_SITES=	http://critical.ch/distfiles/ \
		ftp://ftp.atari.art.pl/stuff/audio/8bit-music-archive/sap/plugins/xmms/
DISTNAME=	sapplug-xmms-${DISTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	XMMS input plugin for playing 8bit Atari(TM) .sap audio files

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12

CXXFLAGS+=	--no-exceptions
WRKSRC=		${WRKDIR}/sapplug-${DISTVERSION}

PLIST_FILES=	lib/xmms/Input/libsap.so

OPTIONS=	OPTIMIZED_CXXLAGS "use optimized C++ flags" on \
		OPTIMIZED_CFLAGS  "use optimized C flags"   on

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CXXLAGS)
CXXFLAGS+=	-fPIC -fpic -funroll-all-loops -fno-strength-reduce \
		-finline-functions -fomit-frame-pointer
.endif
.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-fPIC -fpic -funroll-all-loops -fomit-frame-pointer \
		-fno-strength-reduce
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(}\);\(\ //.*\)|\1\2|' \
		${WRKSRC}/saplib/pokeyNamespace.h
	@${REINPLACE_CMD} -e 's|^\(C[[:alpha:]]*\)|\1?|' \
		${WRKSRC}/saplib/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsap.so ${PREFIX}/lib/xmms/Input/libsap.so

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
