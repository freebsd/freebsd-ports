# New ports collection makefile for:	drivel
# Date created:			Thu Feb 26 23:13:12 CET 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	drivel
PORTVERSION=	1.2.3
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Gnome livejournal client

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui intlhack gtksourceview
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	drivel.schemas

.ifndef(WITHOUT_RHYTHMBOX)
CONFIGURE_ARGS+=	--with-rhythmbox
BUILD_DEPENDS+=		rhythmbox:${PORTSDIR}/audio/rhythmbox
RUN_DEPENDS+=		${BUILD_DEPENDS}
.else
CONFIGURE_ARGS+=	--without-rhythmbox
.endif

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITHOUT_RHYTHMBOX=yes to disable rhythmbox backend"
	@${ECHO_MSG} "Define WITHOUT_GTKSPELL=yes to disable gtkspell"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
