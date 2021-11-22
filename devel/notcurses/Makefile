PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	${ABIVERSION}.4.9
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

USES=		cmake:noninja compiler:c++17-lang localbase ncurses:port \
		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

CMAKE_ON=	USE_QRCODEGEN
# we leave USE_POC=on (and BUILD_TESTING=on) so that we can run some basic
# tests, if not the full notcurses-tester suite.
CMAKE_OFF=	USE_DOCTEST USE_PANDOC

TEST_TARGET=	test

PLIST_SUB=	ABI_VER=${ABIVERSION} \
		REL_VER=${DISTVERSION}

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
