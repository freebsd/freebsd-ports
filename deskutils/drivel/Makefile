# New ports collection makefile for:	drivel
# Date created:			Thu Feb 26 23:13:12 CET 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	drivel
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/Drivel%20%28stable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog editor for GNOME

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 gconf2 gnomevfs2 gtksourceview2 libxml2 gnomedocutils
USE_GSTREAMER=	soup
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:267:env automake:111:env
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	drivel.schemas

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITHOUT_GTKSPELL=yes to disable gtkspell"
	@${ECHO_MSG} ""

pre-configure:
	( cd ${WRKSRC} ; ${AUTORECONF} )

.include <bsd.port.mk>
