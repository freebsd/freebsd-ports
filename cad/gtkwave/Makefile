PORTNAME=	gtkwave
DISTVERSION=	3.3.117
CATEGORIES=	cad
MASTER_SITES=	http://gtkwave.sourceforge.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Electronic Waveform Viewer
WWW=		https://gtkwave.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext gmake gnome \
		gperf pkgconfig shared-mime-info
USE_GNOME=	cairo gdkpixbuf2 gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-update \
		--without-gconf

PORTDOCS=	gtkwave.odt
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES TCL
TCL_DESC=		Enable support for TCL/TK
TCL_USES=		tcl tk
TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
TCL_CONFIGURE_OFF=	--disable-tcl

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} '/^SUBDIRS/s|examples||' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
