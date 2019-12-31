# $FreeBSD$

PORTNAME=	OpenFodder
DISTVERSION=	1.6.0
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Open source port of Cannon Fodder

LICENSE=	BSD3CLAUSE GPLv3+ LGPL21+ MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING.BSD.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPLv2.1.txt
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.MIT.txt
LICENSE_FILE_ZLIB=	${WRKSRC}/COPYING.ZLIB.txt

USES=		compiler:c++14-lang sdl
USE_GITHUB=	yes
USE_SDL=	mixer2
GH_TUPLE=	${PORTNAME}:data:1.7.0:data/Run \
		${PORTNAME}:scripts:c6f3076:scripts/Run/Scripts
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
		${WRKSRC}/Source/ResourceMan.cpp

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
	(cd ${WRKSRC}/Run && ${COPYTREE_SHARE} "${PORTDATA}" \
		 ${STAGEDIR}${DATADIR} "! -name ${PORTNAME} -type f")

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" \
		${STAGEDIR}${DOCSDIR})

do-install-ICONS-on:
	(cd ${WRKDIR}/icons && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/icons)
	(cd ${STAGEDIR}${PREFIX} && ${FIND} share/icons -type f >>${TMPPLIST})

.include <bsd.port.mk>
