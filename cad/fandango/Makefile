# ex:ts=8
# Ports collection makefile for:	fandango
# Date created:			Feb 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fandango
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	elcad
DISTNAME=	k${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python scripted 3D CAD application

LIB_DEPENDS=	python2.3.1:${PORTSDIR}/lang/python23

USE_GL=		yes
USE_GNOME=	gnometarget
USE_KDEBASE_VER=	3
GNU_CONFIGURE=	yes
LDFLAGS+=	-lGL
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
