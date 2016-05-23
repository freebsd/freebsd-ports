# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	genius
PORTVERSION=	1.0.21
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME \
		http://ftp.5z.com/pub/genius/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LICENSE=	GPLv3

BUILD_DEPENDS=	rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libmpfr.so:math/mpfr
RUN_DEPENDS=	rarian-sk-config:textproc/rarian

USES=		desktop-file-utils gmake libtool pathfix pkgconfig \
		readline shared-mime-info tar:xz
USE_GNOME=	gnomedocutils gnomeprefix gtksourceview2 gnomevfs2 vte intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-extra-gcc-optimization \
		--disable-update-mimedb \
		--disable-scrollkeeper
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC}/gtkextra -name "*.c" | ${XARGS} \
		${REINPLACE_CMD} -e 's|inline gint|gint|'

.include <bsd.port.mk>
