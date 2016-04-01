# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	drivel
PORTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/Drivel%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog editor for GNOME

LICENSE=	GPLv2+

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=	GTKSPELL
GTKSPELL_DESC=	Enable GtkSpell support

USES=		desktop-file-utils gettext gmake libtool shared-mime-info pkgconfig tar:bzip2
USE_GNOME=	gconf2 gnomedocutils gnomevfs2 gtksourceview2 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-error-on-warning
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	drivel.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
GTKSPELL_CONFIGURE_OFF=	--without-gtkspell

post-patch:
	@${REINPLACE_CMD} -e '/-g2/s|^|#|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|make -C|$$(MAKE) -C|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/-ldl/s|^|#|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|soup_xmlrpc_message_new|d_soup_xmlrpc_message_new|g' \
		${WRKSRC}/src/soup-xmlrpc-message.[ch] \
		${WRKSRC}/src/xmlrpc.c

.include <bsd.port.mk>
