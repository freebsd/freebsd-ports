PORTNAME=	pioneer
DISTVERSION=	20250501
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space adventure game set in the Milky Way galaxy
WWW=		https://pioneerspacesim.net/

LICENSE=		APACHE20 BSD2CLAUSE CC-BY-SA-3.0 DejaVu GPLv3 IUP \
			MIT SIL ZLIB
LICENSE_COMB=		multi
LICENSE_NAME_DejaVu=	Bitstream Vera and Arev fonts license
LICENSE_NAME_IUP=	Galaxy colour image use policy
LICENSE_NAME_SIL=	SIL open font license version 1.1
LICENSE_FILE_APACHE20=	${WRKSRC}/licenses/Apache-2.0.txt
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/licenses/LZ4.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/licenses/CC-BY-SA-3.0.txt
LICENSE_FILE_DejaVu=	${WRKSRC}/licenses/DejaVu-license.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/GPL-3.txt
LICENSE_FILE_IUP=	${WRKSRC}/licenses/Image\ Use\ Policy\ -\ NASA\ Spitzer\ Space\ Telescope.html
LICENSE_FILE_SIL=	${WRKSRC}/licenses/SIL-1.1.txt
LICENSE_PERMS_DejaVu=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IUP=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# XXX: if you have similar error, try adding failing arch to USE_CHRONO condition in contrib/profiler/Profiler.h
BROKEN_xxx=		fails to build: contrib/profiler/Profiler.h:158:51: inconsistent operand constraints in an 'asm'

LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libfreetype.so:print/freetype2 \
		libsigc-2.0.so:devel/libsigc++20 \
		libvorbisfile.so:audio/libvorbis

USES=		cmake compiler:c++17-lang gl gnome lua:52 pkgconfig sdl
USE_GITHUB=	yes
USE_GL=		gl glu glew
USE_SDL=	image2 sdl2
GH_ACCOUNT=	pioneerspacesim
ALL_TARGET=	all build-data
CMAKE_ARGS=	-DPIONEER_DATA_DIR:PATH="${DATADIR}/data"
CMAKE_ON=	USE_SYSTEM_LIBGLEW USE_SYSTEM_LIBLUA

PORTDATA=	*
PORTDOCS=	AUTHORS.txt Changelog.txt Quickstart.txt \
		README.md editor.txt

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS PROFILER

NOGPUJOBS_DESC=		Disable EnableGPUJobs for config.ini by default
PROFILER_DESC=		Build with internal profiler

DOCS_SUB_LIST=		QUICKSTART_PATH="${DOCSDIR}"
DOCS_SUB_LIST_OFF=	QUICKSTART_PATH="https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}"
PROFILER_CMAKE_BOOL=	PROFILER_ENABLED

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_OFF+=	USE_SSE42
.endif

post-install-DOCS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
