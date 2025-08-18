PORTNAME=	gtkwave
DISTVERSION=	3.3.125
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${DISTNAME}
DISTNAME=	${PORTNAME}-gtk3-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Electronic Waveform Viewer
WWW=		https://gtkwave.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gettext-runtime gmake gnome gperf pkgconfig \
		shared-mime-info
USE_GNOME=	cairo gdkpixbuf gtk30

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-update \
		--enable-gtk3 \
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
