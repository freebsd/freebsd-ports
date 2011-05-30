# New ports collection makefile for:	czmq
# Date created:		2008-07-28
# Whom:			Andrew Thompson <thompsa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	czmq
PORTVERSION=	1.0.0
CATEGORIES=	devel net
MASTER_SITES=	http://download.zeromq.org/
DISTNAME=	czmq-${DISTVERSION}

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	High-level C Binding for zmq

LIB_DEPENDS=	zmq:${PORTSDIR}/devel/zmq
BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libzmq=${LOCALBASE}
USE_LDCONFIG=	yes

MAN7=		czmq.7 \
		zclock.7 \
		zctx.7 \
		zframe.7 \
		zhash.7 \
		zlist.7 \
		zloop.7 \
		zmsg.7 \
		zsocket.7 \
		zsockopt.7 \
		zstr.7 \
		zthread.7

post-configure:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
