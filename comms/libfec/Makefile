# ports collection makefile for:	fec
# Date created:		7 July 2006
# Whom:			db
#
# $FreeBSD$

PORTNAME=	libfec
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	comms astro hamradio math
MASTER_SITES=	http://www.ka9q.net/code/fec/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	fec-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Several forward error correction (FEC) decoders

MAKEFILE=	makefile
MAN3=		simd-viterbi.3 rs.3 dsp.3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	include/fec.h lib/libfec.so lib/libfec.a

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/makefile.in

.include <bsd.port.mk>
