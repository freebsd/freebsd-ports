# New ports collection makefile for:	logjam2
# Date created:				30 Oct 2002
# Whom:					michael johnson <ahze@rgv.net>
#
# $FreeBSD$
#

PORTNAME=	logjam2
PORTVERSION=	4.3.2
CATEGORIES=	deskutils
MASTER_SITES=	http://logjam.danga.com/download/
DISTNAME=	logjam-${PORTVERSION}

MAINTAINER=	mike.patterson@unb.ca
COMMENT=	A GTK2 interface to livejournals, ie www.livejournal.com

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

MAN1=		logjam.1

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack \
		gnomeprefix \
		gtk20 \
		libxml2 \
		intlhack
CONFIGURE_ARGS=	--program-transform-name="s/$$//"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	WITH_XMMS=""
.else
PLIST_SUB+=	WITH_XMMS="@comment "
CONFIGURE_ARGS+=	--without-xmms
.endif

.if defined(WITH_GTKHTML)
USE_GNOME+=	gtkhtml3
.else
CONFIGURE_ARGS+=	--without-gtkhtml
.endif

.if defined(WITH_RSVG)
USE_GNOME+=	librsvg2
.else
CONFIGURE_ARGS+=	--without-librsvg
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "logjam has the following tunable option(s):"
	@${ECHO_MSG} "		WITH_GTKSPELL	Enable spell checking"
	@${ECHO_MSG} "		WITH_XMMS	Enable XMMS music detection"
	@${ECHO_MSG} "		WITH_GTKHTML	Enable GTK HTML3 preview"
	@${ECHO_MSG} "		WITH_RSVG	Enable librsvg"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
