# $FreeBSD$

PORTNAME=	xcwcp

COMMENT=	X11 CW Tutor using unixcw

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcw.so:comms/unixcw

MASTERDIR=	${.CURDIR}/../unixcw

PLIST=		${.CURDIR}/pkg-plist
USE_QT5=	buildtools gui widgets qmake_build
USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xcwcp
XCWCP=		yes
PLIST_FILES=	bin/xcwcp \
		man/man1/xcwcp.1.gz
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xcwcp/xcwcp ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/xcwcp/xcwcp.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
