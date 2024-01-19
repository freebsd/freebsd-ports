PORTNAME=	xcwcp
PORTREVISION=	3

COMMENT=	X11 CW Tutor using unixcw
WWW=		https://www.ibiblio.org/pub/linux/apps/ham/morse/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcw.so:comms/unixcw

MASTERDIR=	${.CURDIR}/../unixcw

USES=		compiler:c++11-lang gettext qt:5
USE_QT=		gui widgets buildtools:build qmake:build
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xcwcp
XCWCP=		yes
PLIST_FILES=	bin/xcwcp \
		share/man/man1/xcwcp.1.gz
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

PLIST=		${.CURDIR}/pkg-plist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xcwcp/xcwcp ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/xcwcp/xcwcp.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include "${MASTERDIR}/Makefile"
