PORTNAME=	xephem
DISTVERSION=	4.2.0
CATEGORIES=	astro

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Interactive astronomical ephemeris program
WWW=		http://www.clearskyinstitute.com/xephem/xephem.html

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/XEphem-${PORTVERSION}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libpng16.so:graphics/png

USES=		gmake groff localbase:ldflags motif shebangfix ssl tar:tgz xorg
USE_GITHUB=	yes
GH_PROJECT=	XEphem
USE_XORG=	x11 xext xft xmu xt

SHEBANG_GLOB=	*.pl

MAKE_ARGS=	CC=${CC}
LDFLAGS+=	-lfontconfig
WRKSRC_SUBDIR=	GUI/xephem

post-patch:
	@${FIND} ${WRKSRC}/../.. -name Makefile -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS+=|g ; \
		s|CFLAGS=|CFLAGS+=|g ; \
		s|LDFLAGS =|LDFLAGS+=|g ; \
		s|-O2 ||g'

pre-build:
	@${ECHO_CMD} 'XEphem.ShareDir: ${PREFIX}/lib/X11/xephem' \
		> ${WRKSRC}/XEphem.ad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XEphem.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XEphem
	${INSTALL_MAN} ${WRKSRC}/xephem.man ${STAGEDIR}${PREFIX}/share/man/man1/xephem.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xephem
	@cd ${WRKSRC}; ${COPYTREE_SHARE} \
		"auxil catalogs fifos fits gallery help lo" \
		${STAGEDIR}${PREFIX}/lib/X11/xephem

.include <bsd.port.mk>
