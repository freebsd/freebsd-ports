# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	yzis
PORTVERSION=	1.0.a.1
PORTREVISION=	12
CATEGORIES=	editors
MASTER_SITES=	http://labs.freehackers.org/attachments/download/45/ \
		http://contribs.martymac.org/FreeBSD-ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a.1/-alpha1/}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Vi-like editor

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		tar:bzip2 cmake gettext perl5 lua:51
USE_XORG=	x11 xext ice
USE_QT4=	qtestlib qmake_build rcc_build uic_build moc_build gui xml
CMAKE_ARGS+=	-DLOCALBASE:STRING="${LOCALBASE}" \
		-DLUA_INCDIR:STRING="${LUA_INCDIR}" \
		-DLUA_LIBDIR:STRING="${LUA_LIBDIR}" \
		-DENABLE_QYZIS:BOOL=ON \
		-DENABLE_LIBYZISRUNNER:BOOL=OFF \
		-DENABLE_TESTS:BOOL=OFF
USE_GCC=	any

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	KYZIS NYZIS DOCS
OPTIONS_SUB=	yes
KYZIS_DESC=	Build kyzis and Yzis kpart
KYZIS_USES=	kde:4
KYZIS_USE=	KDE=kdeprefix,kdelibs,automoc4 QT4=phonon
KYZIS_CMAKE_ON=	-DENABLE_KYZIS:BOOL=ON -DENABLE_KPART_YZIS:BOOL=ON
KYZIS_CMAKE_OFF=	-DENABLE_KYZIS:BOOL=OFF -DENABLE_KPART_YZIS:BOOL=OFF
NYZIS_DESC=	Build nyzis (ncurses frontend)
NYZIS_CPPFLAGS=	-D_XOPEN_SOURCE_EXTENDED
NYZIS_CMAKE_ON=	-DENABLE_NYZIS:BOOL=ON
NYZIS_CMAKE_OFF=	-DENABLE_NYZIS:BOOL=OFF
DOCS_BUILD_DEPENDS=	dot:graphics/graphviz \
		doxygen:devel/doxygen
DOCS_CMAKE_ON=	-DENABLE_DOCUMENTATION:BOOL=ON
DOCS_CMAKE_OFF=	-DENABLE_DOCUMENTATION:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKYZIS}
PLIST_SUB+=	QYZIS="@comment "
.else
PLIST_SUB+=	QYZIS=""
.endif

.include <bsd.port.mk>
