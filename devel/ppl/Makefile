# ex:ts=8
# New ports collection makefile for:	ppl
# Date created:			Feb 5, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ppl
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/%SUBDIR%/ \
		http://www.cs.unipr.it/ppl/Download/ftp/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Parma Polyhedra Library

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-debugging \
		--enable-optimization \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-gmp-includes="${LOCALBASE}/include" \
		--with-gmp-dir="${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

# ppl needs gcc > 3.1, with libgmp4 compiled with the same gcc version
.if ${OSVERSION} < 500035
IGNORE=		"Does not build with older versions of FreeBSD"
.endif

.include <bsd.port.post.mk>
