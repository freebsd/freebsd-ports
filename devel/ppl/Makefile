# ex:ts=8
# New ports collection makefile for:	ppl
# Date created:			Feb 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ppl
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/${PORTVERSION}/ \
		http://www.cs.unipr.it/ppl/Download/ftp/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gmp.5:${PORTSDIR}/math/libgmp4

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
