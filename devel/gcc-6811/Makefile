# New ports collection makefile for:	gcc-6811
# Date created:		Thu Sep 14 11:10:01 CDT 1995
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gcc-6811
PORTVERSION=	2.6.3
CATEGORIES=	devel
MASTER_SITES=	ftp://nyquist.ee.ualberta.ca/pub/motorola/68hc11/gcc/ \
		ftp://ftp.celestial.com/mirrors/gnu/ \
		ftp://ftp.inria.fr/gnu/
DISTFILES=	gcc-6811-fsf.tar.gz gcc-2.6.3.tar.gz

MAINTAINER=	jake@FreeBSD.org

NO_WRKSUBDIR=	yes

post-extract:
	tar -C ${WRKSRC}/gcc-6811-release/gcc -cf - config | \
	  tar -C ${WRKSRC}/gcc-2.6.3 -xvf -

pre-configure:
	cd ${WRKSRC}/gcc-2.6.3; ./configure -host=i386-unknown-freebsd2.0.5 \
	  --target=m6811-local --prefix=${PREFIX}

post-install:
	cd ${PREFIX}/lib/gcc-lib/m6811-local/2.6.3; strip cc1 cpp
	cd ${PREFIX}/bin; strip m6811-local-gcc as6800 asz80 as6811 \
	  as6809 as6805 as6804 asi85 aslink

.include <bsd.port.mk>
