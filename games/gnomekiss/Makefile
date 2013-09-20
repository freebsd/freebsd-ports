# Created by: UMENO Takashi <umeno@rr.iij4u.or.jp>
# $FreeBSD$

PORTNAME=	gnomekiss
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	games gnome
MASTER_SITES=	http://devel.tlrmx.org/kiss/source/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	GNOME version of Kisekae Set System

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USES=		pkgconfig
USE_GNOME=	gnomeprefix gnomehack libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN1=		gnomekiss.1

NO_STAGE=	yes
.include <bsd.port.mk>
