# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	yzis
PORTVERSION=	1.0.a.1
PORTREVISION=	9
CATEGORIES=	editors
MASTER_SITES=	http://labs.freehackers.org/attachments/download/45/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a.1/-alpha1/}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Vi-like editor

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USE_BZIP2=	yes
USE_XORG=	x11 xext ice
USE_LUA=	5.1
LUA_COMPS=	lua
USE_QT4=	qtestlib qmake_build rcc_build uic_build moc_build gui xml
USES=		perl5

USES=		cmake gettext
CMAKE_ARGS+=	-DLOCALBASE:STRING="${LOCALBASE}" \
		-DLUA_INCDIR:STRING="${LUA_INCDIR}" \
		-DLUA_LIBDIR:STRING="${LUA_LIBDIR}" \
		-DENABLE_QYZIS:BOOL=ON \
		-DENABLE_LIBYZISRUNNER:BOOL=OFF \
		-DENABLE_TESTS:BOOL=OFF

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	KYZIS NYZIS
KYZIS_DESC=	Build kyzis and Yzis kpart
NYZIS_DESC=	Build nyzis (ncurses frontend)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKYZIS}
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
USE_QT4+=	phonon
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNYZIS}
CPPFLAGS+=	-D_XOPEN_SOURCE_EXTENDED # ncurses/widec support
CMAKE_ARGS+=	-DENABLE_NYZIS:BOOL=ON
PLIST_SUB+=	PL_NYZIS=""
.else
CMAKE_ARGS+=	-DENABLE_NYZIS:BOOL=OFF
PLIST_SUB+=	PL_NYZIS="@comment "
.endif

.if ${PORT_OPTIONS:MKYZIS}
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

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		doxygen:${PORTSDIR}/devel/doxygen
CMAKE_ARGS+=	-DENABLE_DOCUMENTATION:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_DOCUMENTATION:BOOL=OFF
.endif

.include <bsd.port.post.mk>
