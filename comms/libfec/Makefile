# ports collection makefile for:	fec
# Date created:		7 July 2006
# Whom:			db
#
# $FreeBSD$

PORTNAME=	libfec
PORTVERSION=	2.1.1
CATEGORIES=	comms astro hamradio
MASTER_SITES=	http://www.ka9q.net/code/fec/
DISTNAME=	fec-${PORTVERSION}

MAINTAINER=	db@db.net
COMMENT=	Several forward error correction (FEC) decoders

MAKEFILE=	makefile
MAN3=		simd-viterbi.3 rs.3 dsp.3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
.endif

.include <bsd.port.post.mk>
