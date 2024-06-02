PORTNAME=	OpenFodder
DISTVERSION=	1.9.2
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Open source port of Cannon Fodder
WWW=		http://openfodder.com/

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
GH_TUPLE=	${PORTNAME}:data:1.8.0-1-g070a608:data/Run \
		${PORTNAME}:scripts:dad0473:scripts/Run/Scripts
GH_PROJECT=	${PORTNAME:tl}
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME:tl}.desktop \
		share/metainfo/${PORTNAME:tl}.appdata.xml \
		share/pixmaps/${PORTNAME:tl}.png
PORTDATA=	*
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,clang++,${CXX},' \
		-e 's/ -ferror-limit=100//' \
		-e 's, -I/usr/include[^[:space:]]*,,g' \
		-e 's,git log -n 1 --pretty=,${ECHO_CMD} ,' \
		-e 's,%%h,${DISTVERSIONFULL},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} '/Exec/s/${PORTNAME:tl}/${PORTNAME}/' \
		${WRKSRC}/FreeDesktop/*.desktop
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/Source/ResourceMan.cpp

do-test:
	@(cd ${WRKSRC_data} && ${SETENV} ${TEST_ENV} \
		${WRKSRC}/Run/${PORTNAME} --unit-test-headless)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Run/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/Run && ${COPYTREE_SHARE} "${PORTDATA}" \
		 ${STAGEDIR}${DATADIR} "! -name ${PORTNAME} -type f")
	${INSTALL_DATA} ${WRKSRC}/FreeDesktop/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/FreeDesktop/*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/FreeDesktop/*.appdata.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
