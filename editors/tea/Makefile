# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
PORTVERSION=	43.1.0
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://semiletov.org/tea/dloads/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple and powerful Qt4-based text editor

LICENSE=	GPLv3

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		SPELL
OPTIONS_GROUP_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	ASPELL HUNSPELL

USES=		pkgconfig:build qmake tar:bzip2
USE_GL=		gl
USE_LOCALE=	en_US.UTF-8
USE_QT4=	corelib gui moc_build network rcc_build

LDFLAGS+=	-lz
PLIST_FILES=	bin/tea share/pixmaps/tea_icon_v2.png
PORTDOCS=	*

DESKTOP_ENTRIES="TEA" "" "${PREFIX}/share/pixmaps/tea_icon_v2.png" \
		"${PORTNAME}" "" ""

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_QMAKE_OFF=	CONFIG+=noaspell

HUNSPELL_LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell
HUNSPELL_QMAKE_OFF=	CONFIG+=nohunspell

post-patch:
	@${REINPLACE_CMD} -e \
		's|Q_OS_LINUX|Q_OS_UNIX|' ${WRKSRC}/document.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include|' ${WRKSRC}/src.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tea ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/tea_icon_v2.png ${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/manuals \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
