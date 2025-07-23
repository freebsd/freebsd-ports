PORTNAME=	lepton-eda
PORTVERSION=	1.9.18
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	https://github.com/lepton-eda/lepton-eda/releases/download/${PORTVERSION}-20220529/

MAINTAINER=	graahnul.grom@gmail.com
COMMENT=	Lepton Electronic Design Automation
WWW=		https://github.com/lepton-eda/lepton-eda

LICENSE=	GPLv2+

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libGLdispatch.so:graphics/libglvnd \
		libgmp.so:math/gmp \
		libgraphite2.so:graphics/graphite2 \
		libgtkextra-x11-3.0.so:x11-toolkits/gtkextra \
		libharfbuzz.so:print/harfbuzz \
		libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libstroke.so:devel/libstroke \
		libunistring.so:devel/libunistring

USES=		desktop-file-utils gettext-tools gnome groff:build \
		guile:2.2,3.0,conflicts iconv:wchar_t libtool localbase \
		makeinfo perl5 pkgconfig shared-mime-info shebangfix \
		xorg
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
USE_GNOME=	cairo gdkpixbuf gtk20
USE_GL=		egl gl
USE_LDCONFIG=	yes

SHEBANG_FILES=	utils/pcb_backannotate/lepton-pcb_backannotate \
		utils/refdes_renum/lepton-refdes_renum \
		utils/symfix/lepton-symfix

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-guild
INSTALL_TARGET=	install-strip

INFO=		lepton-scheme lepton-manual
PORTEXAMPLES=	examples/*

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} -e \
		's,\$$(docdir)/examples,\$$(datadir)/examples/lepton-eda,' \
		${WRKSRC}/examples/Makefile.in \
		${WRKSRC}/examples/RF_Amp/Makefile.in \
		${WRKSRC}/examples/TwoStageAmp/Makefile.in \
		${WRKSRC}/examples/gTAG/Makefile.in \
		${WRKSRC}/examples/lightning_detector/Makefile.in

.include <bsd.port.mk>
