# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
PORTVERSION=	36.0.2
CATEGORIES=	editors
MASTER_SITES=	http://semiletov.org/tea/dloads/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Simple and powerful Qt4-based text editor

LICENSE=	GPLv3

OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	ASPELL

USE_BZIP2=	yes
USE_QT4=	gui moc_build qmake_build rcc_build
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/tea share/pixmaps/tea_icon_v2.png

DESKTOP_ENTRIES="TEA" "" "${PREFIX}/share/pixmaps/tea_icon_v2.png" \
		"${PORTNAME}" "" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
QMAKEFLAGS+=	USE_ASPELL=true
.else
QMAKEFLAGS+=	USE_ASPELL=false
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	hunspell:${PORTSDIR}/textproc/hunspell
QMAKEFLAGS+=	USE_HUNSPELL=true
.else
QMAKEFLAGS+=	USE_HUNSPELL=false
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|Q_OS_LINUX|Q_OS_UNIX|' ${WRKSRC}/document.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include|' ${WRKSRC}/src.pro

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	(cd ${WRKSRC}/bin \
		&& ${INSTALL_PROGRAM} tea ${PREFIX}/bin)
	(cd ${WRKSRC}/icons \
		&& ${INSTALL_DATA} tea_icon_v2.png ${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
