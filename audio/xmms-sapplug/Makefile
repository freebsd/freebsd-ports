# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-sapplug
DISTVERSION=	0.3f
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	CRITICAL
DISTNAME=	sapplug-xmms-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS input plugin for playing 8bit Atari(TM) .sap audio files

LICENSE=	GPLv2

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USES=		gmake compiler
USE_GNOME=	glib12
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/sapplug-${DISTVERSION}

PLIST_FILES=	lib/xmms/Input/libsap.so

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

CFLAGS_amd64=	-fpic -DPIC
CFLAGS_ia64=	-fpic -DPIC

.include <bsd.port.pre.mk>

# clang can build this without -fno-exceptions
.if ${COMPILER_TYPE} == "gcc"
CXXFLAGS+=	-fno-exceptions
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CXXFLAGS+=	-fPIC -fpic -funroll-all-loops -fno-strength-reduce \
		-finline-functions -fomit-frame-pointer
CFLAGS+=	-fPIC -fpic -funroll-all-loops -fomit-frame-pointer \
		-fno-strength-reduce
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(}\);\(\ //.*\)|\1\2|' \
		${WRKSRC}/saplib/pokeyNamespace.h
	@${REINPLACE_CMD} -e 's|^\(C[[:alpha:]]*\)|\1?|' \
		${WRKSRC}/saplib/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_DATA} ${WRKSRC}/libsap.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Input/libsap.so

.include <bsd.port.post.mk>
