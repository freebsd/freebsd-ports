# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	librevisa-vish
PORTVERSION=	0.0.20130714
CATEGORIES=	devel
MASTER_SITES=	http://www.librevisa.org/download/
DISTNAME=	vish-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source VISA shell for interfacing test and measurement equipment

LIB_DEPENDS=	libvisa.so:devel/librevisa

USES=		gmake
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lvisa

.include <bsd.port.mk>
