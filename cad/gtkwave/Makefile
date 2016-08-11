# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkwave
PORTVERSION=	3.3.73
CATEGORIES=	cad
MASTER_SITES=	http://gtkwave.sourceforge.net/

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		desktop-file-utils gettext gmake gperf pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-update
USE_GNOME=	cairo gtk20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	TCL GCONF
TCL_DESC=	Enable support for TCL/TK
TCL_USES=	tcl tk
TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
TCL_CONFIGURE_OFF=	--disable-tcl

GCONF_CONFIGURE_WITH=	gconf
GCONF_USE=		GNOME=gconf2

PORTDOCS=	gtkwave.odt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
