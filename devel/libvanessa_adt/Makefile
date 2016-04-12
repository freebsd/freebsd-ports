# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	libvanessa_adt
PORTVERSION=	0.0.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://horms.net/projects/vanessa/download/vanessa_adt/${PORTVERSION}/
DISTNAME=	vanessa_adt-${PORTVERSION}

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Library that provides ADTs (queues, dynamic arrays, and more)

LIB_DEPENDS=	libvanessa_logger.so:devel/libvanessa_logger

USE_LDCONFIG=	yes

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|test debian||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
