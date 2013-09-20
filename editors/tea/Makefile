# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
PORTVERSION=	36.0.3
CATEGORIES=	editors
MASTER_SITES=	http://semiletov.org/tea/dloads/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Simple and powerful Qt4-based text editor

LICENSE=	GPLv3

OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	ASPELL

USE_BZIP2=	yes
USE_QT4=	gui moc_build qmake_build rcc_build

PLIST_FILES=	bin/tea share/pixmaps/tea_icon_v2.png
PORTDOCS=	*

DESKTOP_ENTRIES="TEA" "" "${PREFIX}/share/pixmaps/tea_icon_v2.png" \
		"${PORTNAME}" "" ""

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	libaspell.so:${PORTSDIR}/textproc/aspell
QMAKEFLAGS+=	USE_ASPELL=true
.else
QMAKEFLAGS+=	USE_ASPELL=false
.endif

.if ${PORT_OPTIONS:MHUNSPELL}
LIB_DEPENDS+=	libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell
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
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/manuals \
		&& ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
