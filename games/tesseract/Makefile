PORTNAME=	tesseract
DISTVERSION=	2014_05_12
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/${PORTNAME}/
PKGNAMESUFFIX=	-game
DISTNAME=	${PORTNAME}_${DISTVERSION}_first_edition_linux

MAINTAINER=	operator@myrechenzentrum.net
COMMENT=	Smooth FPS with map editing, instagib, DM and CTF
WWW=		http://tesseract.gg/

LICENSE=	ZLIB

LIB_DEPENDS=	libenet.so:net/enet
RUN_DEPENDS=	${PKGBASE}-data>=${PORTVERSION}:games/tesseract-data

USES=		gmake pkgconfig tar:xz
EXCLUDE=	bin_unix config media screenshot src/enet src/lib\* src/xcode
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	# empty
SUB_FILES=	tess_wrapper
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=CLIENT DEDICATED
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=CLIENT DEDICATED MASTER

CLIENT_DESC=		Build client
CLIENT_USES=		gl sdl xorg
CLIENT_USE=		GL=gl SDL=image2,mixer2 XORG=x11
CLIENT_ALL_TARGET=	client
CLIENT_PLIST_FILES=	bin/tess_client libexec/tess_client
CLIENT_DESKTOP_ENTRIES=	"Tesseract" \
			"" \
			"${DATADIR}/media/interface/cube.png" \
			"tess_client" \
			"Game;Shooter;" \
			""

DEDICATED_DESC=		Build dedicated server
DEDICATED_ALL_TARGET=	server
DEDICATED_PLIST_FILES=	bin/tess_server libexec/tess_server

MASTER_DESC=		Build master server
MASTER_ALL_TARGET=	master
MASTER_PLIST_FILES=	bin/tess_master libexec/tess_master

post-patch:
	@${REINPLACE_CMD} -e '/OBJS.*PCH/d' \
		-e '/-fomit-frame-pointer/d' \
		-e 's,-I/usr/X11R6/include,,' \
		-e 's,-L/usr/X11R6/lib,,' \
		-e 's,libenet ,,' \
		-e 's,-Ienet/include,`pkg-config --cflags libenet`,' \
		-e 's,-Lenet -lenet,`pkg-config --libs libenet`,' \
		${BUILD_WRKSRC}/Makefile

do-install:
	for f in ${PLIST_FILES:Mbin/*}; do \
		${INSTALL_SCRIPT} ${WRKDIR}/tess_wrapper \
			${STAGEDIR}${PREFIX}/$$f; \
	done
	for f in ${PLIST_FILES:Mlibexec/*}; do \
		${INSTALL_PROGRAM} ${BUILD_WRKSRC}/$${f##*/} \
			${STAGEDIR}${PREFIX}/$${f%/*}; \
	done

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
