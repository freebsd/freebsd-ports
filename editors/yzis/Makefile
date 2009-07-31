# New ports collection makefile for:	yzis
# Date created:        Tue May 20 19:00:00 UTC 2008
# Whom:                Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	yzis
PORTVERSION=	1.0.a.1
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://labs.freehackers.org/attachments/download/45/ \
		http://contribs.martymac.com/FreeBSD-ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a.1/-alpha1/}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Vi-like editor

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XORG=	x11 xext ice
USE_LUA=	5.1
LUA_COMPS=	lua
USE_QT_VER=	4
QT_COMPONENTS=	qtestlib qmake_build rcc_build uic_build moc_build gui xml
USE_PERL5=	yes

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_BUILD_TYPE=	Release
CMAKE_ARGS+=	-DLOCALBASE:STRING="${LOCALBASE}" \
		-DLUA_INCDIR:STRING="${LUA_INCDIR}" \
		-DLUA_LIBDIR:STRING="${LUA_LIBDIR}" \
		-DENABLE_QYZIS:BOOL=ON \
		-DENABLE_LIBYZISRUNNER:BOOL=OFF \
		-DENABLE_TESTS:BOOL=OFF

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
OPTIONS=	KYZIS "Build Kyzis and Yzis kpart" off \
		NYZIS "Build nyzis (ncurses frontend)" off

.include <bsd.port.options.mk>

.if defined(WITH_KYZIS)
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_NYZIS)
CPPFLAGS+=	-D_XOPEN_SOURCE_EXTENDED # ncurses/widec support
CMAKE_ARGS+=	-DENABLE_NYZIS:BOOL=ON
PLIST_SUB+=	PL_NYZIS=""
.else
CMAKE_ARGS+=	-DENABLE_NYZIS:BOOL=OFF
PLIST_SUB+=	PL_NYZIS="@comment "
.endif

.if defined(WITH_KYZIS)
LIB_DEPENDS+=	phonon.4:${PORTSDIR}/multimedia/phonon
CMAKE_ARGS+=	-DENABLE_KYZIS:BOOL=ON \
		-DENABLE_KPART_YZIS:BOOL=ON
PLIST_SUB+=	PL_KYZIS=""
PLIST_SUB+=	PL_QYZIS="@comment "
.else
CMAKE_ARGS+=	-DENABLE_KYZIS:BOOL=OFF \
		-DENABLE_KPART_YZIS:BOOL=OFF
PLIST_SUB+=	PL_KYZIS="@comment "
PLIST_SUB+=	PL_QYZIS=""
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		doxygen:${PORTSDIR}/devel/doxygen
CMAKE_ARGS+=	-DENABLE_DOCUMENTATION:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_DOCUMENTATION:BOOL=OFF
.endif

.include <bsd.port.post.mk>
