# Created by: Bruce M Simpson <bms@FreeBSD.org>

PORTNAME=	gtkwave
DISTVERSION=	3.3.111
CATEGORIES=	cad
MASTER_SITES=	http://gtkwave.sourceforge.net/

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext gmake \
		gnome gperf pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-update
USE_GNOME=	cairo gdkpixbuf2 gtk20

OPTIONS_DEFINE=	TCL GCONF DOCS EXAMPLES
TCL_DESC=	Enable support for TCL/TK
TCL_USES=	tcl tk
TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
TCL_CONFIGURE_OFF=	--disable-tcl

GCONF_CONFIGURE_WITH=	gconf
GCONF_USE=		GNOME=gconf2

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
