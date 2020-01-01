# $FreeBSD$

PORTNAME=	lepton-eda
PORTVERSION=	1.9.9
DISTVERSIONSUFFIX=	-20191003
CATEGORIES=	cad

MAINTAINER=	graahnul.grom@gmail.com
COMMENT=	Lepton Electronic Design Automation

LICENSE=	GPLv2+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libguile-2.2.so:lang/guile2 \
		libpng.so:graphics/png \
		libstroke.so:devel/libstroke

USES=		autoreconf desktop-file-utils gettext-tools gnome \
		groff:build libtool localbase makeinfo pathfix perl5 \
		pkgconfig python:2.7,run shared-mime-info shebangfix
USE_GITHUB=	yes
USE_GNOME=	cairo gtk20
USE_LDCONFIG=	yes

SHEBANG_FILES=	utils/scripts/lepton-tragesym \
		utils/scripts/lepton-archive.py \
		utils/scripts/gschupdate \
		utils/scripts/gsymupdate \
		utils/scripts/lepton-pcb_backannotate \
		utils/scripts/lepton-refdes_renum \
		utils/scripts/lepton-symfix \
		examples/lightning_detector/bom

PORTEXAMPLES=	examples/*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes

INFO=	lepton-scheme

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
