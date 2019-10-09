# $FreeBSD$

PORTNAME=	OpenFodder
DISTVERSION=	1.5.3
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Open source port of Cannon Fodder

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

USES=		compiler:c++14-lang sdl
USE_GITHUB=	yes
USE_SDL=	mixer2
GH_TUPLE=	${PORTNAME}:data:1.6.0:data
GH_PROJECT=	${PORTNAME:tl}
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*.md

DESKTOP_ENTRIES="${PORTNAME}" \
		"" \
		"${PORTNAME:tl}" \
		"${PORTNAME}" \
		"Game;ActionGame;" \
		""

OPTIONS_DEFINE=	DOCS ICONS
OPTIONS_DEFAULT=ICONS

ICONS_BUILD_DEPENDS=	mogrify:graphics/ImageMagick6

post-patch:
	@${REINPLACE_CMD} -e 's,clang++,${CXX},' \
		-e 's/ -ferror-limit=100//' \
		-e 's, -I/usr/include[^[:space:]]*,,g' \
		-e 's,git log -n 1 --pretty=,${ECHO_CMD} ,' \
		-e 's,%%h,${DISTVERSIONFULL},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/Source/stdafx.cpp

post-build-ICONS-on:
	@for size in 16x16 24x24 32x32 48x48 57x57; do \
		${MKDIR} ${WRKDIR}/icons/hicolor/$$size/apps; \
	done
	@mogrify -verbose -set filename:size %wx%h -format png \
		 -path ${WRKDIR}/icons/hicolor/%\[filename:size]/apps \
		${WRKSRC}/Projects/${PORTNAME:tl}.ico

do-test:
	@(cd ${WRKSRC_data} && ${SETENV} ${TEST_ENV} \
		${WRKSRC}/Run/${PORTNAME} --unit-test-headless)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Run/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC_data} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" \
		${STAGEDIR}${DOCSDIR})

do-install-ICONS-on:
	(cd ${WRKDIR}/icons && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/icons)
	(cd ${STAGEDIR}${PREFIX} && ${FIND} share/icons -type f >>${TMPPLIST})

.include <bsd.port.mk>
