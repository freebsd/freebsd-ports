# ex:ts=8
# New ports collection makefile for:	ppl
# Date created:			Feb 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ppl
PORTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/${PORTVERSION}/ \
		http://www.cs.unipr.it/ppl/Download/ftp/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The Parma Polyhedra Library

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_LIBTOOL=	yes
USE_GCC=	3.1
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-install:
	@${RMDIR} ${PREFIX}/lib/ppl

.include <bsd.port.mk>
