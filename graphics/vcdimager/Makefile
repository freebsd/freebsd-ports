# New ports collection makefile for:   vcdimager
# Date created:                                16 April 2001
# Whom:                                        Harold Gutch <logix@foobar.franken.de>
#
# $FreeBSD$

PORTNAME=	vcdimager
PORTVERSION=	0.7.12
CATEGORIES=	graphics
MASTER_SITES=	http://www.vcdimager.org/pub/vcdimager/vcdimager-0.7_UNSTABLE/

MAINTAINER=	freebsdports@arved.de

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		xml2:${PORTSDIR}/textproc/libxml2

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		vcdimager.1 vcdxminfo.1 vcdxrip.1 vcdxgen.1 vcdxbuild.1 vcddebug.1

.include <bsd.port.mk>
