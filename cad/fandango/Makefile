# ex:ts=8
# Ports collection makefile for:	fandango
# Date created:			Feb 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fandango
PORTVERSION=	0.2.6.1
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	SF/elcad/${PORTNAME}/${PORTVERSION}%20%28builds-in-Gutsy%29
DISTNAME=	k${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python scripted 3D CAD application

LIB_DEPENDS=	python2.3.1:${PORTSDIR}/lang/python23

USE_GL=		yes
USE_GNOME=	gnometarget
USE_GETTEXT=	yes
USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool:22
LDFLAGS+=	-lGL
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
