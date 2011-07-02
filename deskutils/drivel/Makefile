# New ports collection makefile for:	drivel
# Date created:			Thu Feb 26 23:13:12 CET 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	drivel
PORTVERSION=	3.0.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/Drivel%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog editor for GNOME

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup

OPTIONS=	GTKSPELL "Enable GtkSpell support" On

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_GNOME=	gconf2 gnomedocutils gnomevfs2 gtksourceview2
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
MAKE_JOBS_SAFE=	yes

GCONF_SCHEMAS=	drivel.schemas

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTKSPELL)
CONFIGURE_ARGS+=	--without-gtkspell
.else
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-g2/s|^|#|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|make -C|$$(MAKE) -C|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/-ldl/s|^|#|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
