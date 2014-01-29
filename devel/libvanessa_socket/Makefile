# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	libvanessa_socket
PORTVERSION=	0.0.12
CATEGORIES=	devel
MASTER_SITES=	http://horms.net/projects/vanessa/download/vanessa_socket/${PORTVERSION}/
DISTNAME=	vanessa_socket-${PORTVERSION}

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Library that provides a simple layer for TCP/IP socket operations

LIB_DEPENDS=	libvanessa_logger.so:${PORTSDIR}/devel/libvanessa_logger \
		libpopt.so:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USES=	pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e '/^SUBDIRS/s|debian||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
