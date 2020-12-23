# $FreeBSD$

PORTNAME=	lepton-eda
PORTVERSION=	1.9.13
CATEGORIES=	cad
MASTER_SITES=	https://github.com/lepton-eda/lepton-eda/releases/download/${PORTVERSION}-20201211/

MAINTAINER=	graahnul.grom@gmail.com
COMMENT=	Lepton Electronic Design Automation

LICENSE=	GPLv2+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libguile-2.2.so:lang/guile2 \
		libpng.so:graphics/png \
		libstroke.so:devel/libstroke \
		libgtkextra-x11-3.0.so:x11-toolkits/gtkextra

USES=		desktop-file-utils gettext-tools gnome \
		groff:build libtool localbase makeinfo pathfix perl5 \
		pkgconfig shared-mime-info shebangfix
USE_GNOME=	cairo gtk20
USE_LDCONFIG=	yes

SHEBANG_FILES=	utils/scripts/lepton-pcb_backannotate \
		utils/scripts/lepton-refdes_renum \
		utils/scripts/lepton-symfix

PORTEXAMPLES=	examples/*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes

INFO=	lepton-scheme lepton-manual

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
	${REINPLACE_CMD} -e \
		's,\$$(docdir)/examples,\$$(datadir)/examples/lepton-eda,' \
		${WRKSRC}/examples/Makefile.in \
		${WRKSRC}/examples/RF_Amp/Makefile.in \
		${WRKSRC}/examples/TwoStageAmp/Makefile.in \
		${WRKSRC}/examples/gTAG/Makefile.in \
		${WRKSRC}/examples/lightning_detector/Makefile.in

.include <bsd.port.mk>
