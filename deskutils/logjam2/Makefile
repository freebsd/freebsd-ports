# New ports collection makefile for:	logjam2
# Date created:				30 Oct 2002
# Whom:					michael johnson <ahze@rgv.net>
#
# $FreeBSD$
#

PORTNAME=	logjam2
PORTVERSION=	4.1.2
CATEGORIES=	deskutils
MASTER_SITES=	http://logjam.danga.com/download/
DISTNAME=	logjam-${PORTVERSION}

MAINTAINER=	mike.patterson@unb.ca
COMMENT=	A GTK2 interface to livejournals, ie www.livejournal.com

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

MAN1=		logjam.1

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libxml2
CONFIGURE_ARGS= --program-transform-name="s/$$//"

.ifdef(WITH_GTKSPELL)
LIB_DEPENDS+=   gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.else
CONFIGURE_ARGS+=        --without-gtkspell
.endif

.ifdef(WITH_XMMS)
LIB_DEPENDS+=	xmms.3:${PORTSDIR}/multimedia/xmms
.else
CONFIGURE_ARGS+=	--without-xmms
.endif

.ifdef(WITH_GTKHTML)
LIB_DEPENDS+=	gtkhtml-3.0.1:${PORTSDIR}/www/gtkhtml3
.else
CONFIGURE_ARGS+=	--without-gtkhtml
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "logjam has the following tunable option(s):"
	@${ECHO_MSG} "		WITH_GTKSPELL	Enable spell checking"
	@${ECHO_MSG} "		WITH_XMMS	Enable XMMS music detection"
	@${ECHO_MSG} "		WITH_GTKHTML	Enable GTK HTML3 preview"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
