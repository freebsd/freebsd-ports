PORTNAME=	geany
PORTVERSION=	1.38
CATEGORIES=	devel editors
MASTER_SITES=	https://download.geany.org/ SF

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Fast and lightweight GTK+ IDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gmake \
		gnome libtool localbase pathfix pkgconfig python:build \
		shebangfix tar:bzip2
USE_GNOME=	cairo gtk30 intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	scripts/gen-api-gtkdoc.py

OPTIONS_DEFINE=	DOCS NLS THEMES VTE
OPTIONS_DEFAULT=	VTE
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

VTE_DESC=	Embedded virtual terminal
VTE_CONFIGURE_ENABLE=	vte
VTE_USE=	GNOME=vte3

THEMES_DESC=	Additional color schemes
THEMES_RUN_DEPENDS=	${LOCALBASE}/share/geany/colorschemes/bespin.conf:devel/geany-themes

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|po||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
