# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	drivel
PORTVERSION=	3.0.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/Drivel%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog editor for GNOME

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=	GTKSPELL
GTKSPELL_DESC=	Enable GtkSpell support

USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake shared-mime-info pkgconfig
USE_GNOME=	gconf2 gnomedocutils gnomevfs2 gtksourceview2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-error-on-warning
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	drivel.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-g2/s|^|#|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|make -C|$$(MAKE) -C|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/-ldl/s|^|#|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
