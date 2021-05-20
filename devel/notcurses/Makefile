PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	${ABIVERSION}.3.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/:docs
DISTFILES=	${PORTNAME}-doc-${DISTVERSION}.tar.gz:docs

MAINTAINER=	nickblack@linux.com
COMMENT=	TUI library for modern terminal emulators

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libqrcodegen.so:graphics/qr-code-generator \
		libunistring.so:devel/libunistring

USES=		cmake:noninja compiler:c++17-lang localbase \
		ncurses:port pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING USE_PANDOC

TEST_TARGET=	test

PLIST_SUB=	REL_VER=${DISTVERSION} ABI_VER=${ABIVERSION}

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

ABIVERSION=	2

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install(FILES $${MARKDOWN} DESTINATION $${CMAKE_INSTALL_DOCDIR})|#install(FILES $${MARKDOWN} DESTINATION $${CMAKE_INSTALL_DOCDIR})|' \
		${WRKSRC}/CMakeLists.txt

post-install-MANPAGES-on:
	${MKDIR} ${STAGEDIR}${MANPREFIX}/man/man1 ${STAGEDIR}${MANPREFIX}/man/man3
	# we don't want to install e.g. "notcurses-x.x.1"
	${FIND} ${WRKDIR} -maxdepth 1 -type f -iname \*.1 -execdir ${INSTALL_MAN} {} ${STAGEDIR}${MANPREFIX}/man/man1 \;
	${FIND} ${WRKDIR} -maxdepth 1 -type f -iname \*.3 -execdir ${INSTALL_MAN} {} ${STAGEDIR}${MANPREFIX}/man/man3 \;

.include <bsd.port.mk>
