# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	yzis
PORTVERSION=	1.0.a.1
PORTREVISION=	19
CATEGORIES=	editors
MASTER_SITES=	http://labs.freehackers.org/attachments/download/45/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a.1/-alpha1/}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Vi-like editor

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL

USES=		qt:4 tar:bzip2 cmake gettext gnome perl5 lua:51
USE_XORG=	x11 xext ice
USE_QT=		corelib qtestlib qmake_build rcc_build uic_build moc_build gui xml
CMAKE_ARGS+=	-DLOCALBASE:STRING="${LOCALBASE}" \
		-DLUA_INCDIR:STRING="${LUA_INCDIR}" \
		-DLUA_LIBDIR:STRING="${LUA_LIBDIR}" \
		-DENABLE_QYZIS:BOOL=ON \
		-DENABLE_LIBYZISRUNNER:BOOL=OFF \
		-DENABLE_TESTS:BOOL=OFF
USE_GCC=	any

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NYZIS DOXYGEN
OPTIONS_SUB=	yes
NYZIS_DESC=	Build nyzis (ncurses frontend)
NYZIS_CPPFLAGS=	-D_XOPEN_SOURCE_EXTENDED
NYZIS_CMAKE_ON=	-DENABLE_NYZIS:BOOL=ON
NYZIS_CMAKE_OFF=	-DENABLE_NYZIS:BOOL=OFF
DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
DOXYGEN_CMAKE_ON=	-DENABLE_DOCUMENTATION:BOOL=ON
DOXYGEN_CMAKE_OFF=	-DENABLE_DOCUMENTATION:BOOL=OFF

.include <bsd.port.mk>
