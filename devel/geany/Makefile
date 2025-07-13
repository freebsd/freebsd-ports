PORTNAME=	geany
PORTVERSION=	2.1
CATEGORIES=	devel editors
MASTER_SITES=	https://download.geany.org/ \
		SF

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Fast and lightweight GTK IDE
WWW=		https://www.geany.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gmake \
		gnome iconv libtool localbase pathfix pkgconfig python:build \
		shebangfix tar:bzip2
USE_GNOME=	cairo gdkpixbuf gtk30 intltool
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/gen-api-gtkdoc.py
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	geany-themes

OPTIONS_DEFINE=		DOCS NLS VTE
OPTIONS_DEFAULT=	VTE
OPTIONS_SUB=		yes

VTE_DESC=	Embedded virtual terminal

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

VTE_USE=		GNOME=vte3
VTE_CONFIGURE_ENABLE=	vte

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|po||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
