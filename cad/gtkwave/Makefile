PORTNAME=	gtkwave
DISTVERSION=	3.3.111
CATEGORIES=	cad
MASTER_SITES=	http://gtkwave.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext gmake \
		gnome gperf pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-update \
		--without-gconf
USE_GNOME=	cairo gdkpixbuf2 gtk20

OPTIONS_DEFINE=	TCL DOCS EXAMPLES
TCL_DESC=	Enable support for TCL/TK
TCL_USES=	tcl tk
TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
TCL_CONFIGURE_OFF=	--disable-tcl

PORTEXAMPLES=	*
PORTDOCS=	gtkwave.odt

post-patch-EXAMPLES-off:
	${REINPLACE_CMD} '/^SUBDIRS/s|examples||' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
