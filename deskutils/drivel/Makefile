# New ports collection makefile for:	drivel
# Date created:			Thu Feb 26 23:13:12 CET 2004
# Whom:				Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	drivel
PORTVERSION=	2.0.2
PORTREVISION=	10
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/Drivel%20%28stable%29/${PORTVERSION}

MAINTAINER=	jbq@caraldi.com
COMMENT=	Blog editor for GNOME

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui intlhack gtksourceview
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libtool:22
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
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITHOUT_RHYTHMBOX=yes to disable rhythmbox backend"
	@${ECHO_MSG} "Define WITHOUT_GTKSPELL=yes to disable gtkspell"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|;;|;|g' \
		${WRKSRC}/src/journal.c \
		${WRKSRC}/src/msg_queue.c

.include <bsd.port.mk>
