# New ports collection makefile for:	edje
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	edje
PORTVERSION=	0.5.0.024
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Edje is a complex graphical design and layout engine

LIB_DEPENDS=	embryo.9:${PORTSDIR}/lang/embryo \
		eet.9:${PORTSDIR}/devel/eet \
		Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		evas.1:${PORTSDIR}/graphics/evas \
		ecore.1:${PORTSDIR}/x11/ecore

GNU_CONFIGURE=	yes
USE_GCC=	3.4
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

.include <bsd.port.post.mk>
