# New ports collection makefile for:	 gnotepad+
# Date created:		08 March 1999
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	gnotepad+
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	editors www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnotepad
.if !defined(NOPORTDOCS)
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-help-${DOCVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK-based text/HTML editor

DOCVERSION=	1.2.0

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_XPM=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	gnp.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|\(use_gtkhtml=\)yes|\1no|g' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-extract:
	@${MV} ${WRKSRC}/docs ${WRKSRC}/docs.old
	@${CP} -R ${WRKDIR}/${PORTNAME}-help-${DOCVERSION}/docs ${WRKSRC}/docs
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME=	gnomeprefix gnomelibs
PKGNAMESUFFIX=	-gnome
PLIST_SUB=	DATADIR="share/gnome"
.else
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB=	DATADIR="share"
.endif

.include <bsd.port.post.mk>
