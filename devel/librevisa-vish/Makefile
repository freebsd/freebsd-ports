# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	librevisa-vish
PORTVERSION=	0.0.20130714
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.librevisa.org/download/
DISTNAME=	vish-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source VISA shell for interfacing test and measurement equipment

LIB_DEPENDS=	libvisa.so:devel/librevisa

USES=		compiler:c++11-lang localbase:ldflags
GNU_CONFIGURE=	yes

LDFLAGS+=	-lvisa

.include <bsd.port.mk>
