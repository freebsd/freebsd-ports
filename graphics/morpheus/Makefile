# New ports collection makefile for:	morpheus
# Date created:				14 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	morpheus
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.winnicki.net/morpheus/meat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mesh (3D model) viewer for GNOME desktop

LIB_DEPENDS=	morph.0:${PORTSDIR}/graphics/libmorph \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GL=		glut
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
