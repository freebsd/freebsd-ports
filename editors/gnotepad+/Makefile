# New ports collection makefile for:	 gnotepad+
# Date created:		08 March 1999
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	gnotepad+
PORTVERSION=	1.3.3
PORTREVISION=	7
CATEGORIES=	editors www gnome
MASTER_SITES=	SF/gnotepad/gnotepad-stable/${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-help-${DOCVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple GTK-based text/HTML editor

DOCVERSION=	1.2.0

USE_GETTEXT=	yes
USE_XORG=	xpm
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	gnp.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|\(use_gtkhtml=\)yes|\1no|g' ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS="@comment "
post-extract:
	@${MV} ${WRKSRC}/docs ${WRKSRC}/docs.old
	@${CP} -R ${WRKDIR}/${PORTNAME}-help-${DOCVERSION}/docs ${WRKSRC}/docs
.else
PLIST_SUB+=	NOPORTDOCS=""
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS+=--disable-gnome
.endif

.include <bsd.port.post.mk>
