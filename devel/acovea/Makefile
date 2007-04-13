# New ports collection makefile for:	acovea
# Date created:		2006-08-01
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	acovea
PORTVERSION=	5.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.coyotegulch.com/distfiles/
DISTNAME=	libacovea-${PORTVERSION}

MAINTAINER=	trasz@freebsd.org
COMMENT=	Tool to find the "best" compiler options using genetic algorithm

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		evocosm-3.1.1:${PORTSDIR}/devel/libevocosm

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${PREFIX}/include/ LDFLAGS=-L${PREFIX}/lib/

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-lrt,,g' ${WRKSRC}/config/*

.include <bsd.port.post.mk>
