# New ports collection makefile for:	adpcm
# Date created:				17 Oct 2001
# Whom:					Andrew <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	adpcm
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cwi.nl/pub/audio/
DISTNAME=	adpcm
EXTRACT_SUFX=	.shar

MAINTAINER=		andrew@ugh.net.au
COMMENT=	An Intel/DVI IMA ADPCM codec library

NO_WRKSUBDIR=	true
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=
MAN3=		adpcm.3
MANCOMPRESSED=	no
INSTALLS_SHLIB=	yes
LIBVERSION=	1

pre-install:
	${MKDIR} ${PREFIX}/share/doc/adpcm

do-install:
	${INSTALL_DATA} ${WRKSRC}/adpcm.h ${PREFIX}/include/adpcm.h
	${INSTALL_DATA} ${WRKSRC}/libadpcm.a ${PREFIX}/lib/libadpcm.a
	${INSTALL_DATA} ${WRKSRC}/libadpcm.so.${LIBVERSION} ${PREFIX}/lib/libadpcm.so.${LIBVERSION}
	${LN} -sf ${PREFIX}/lib/libadpcm.so.${LIBVERSION} ${PREFIX}/lib/libadpcm.so
	${INSTALL_MAN} ${WRKSRC}/adpcm.2 ${PREFIX}/man/man3/adpcm.3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/adpcm/README
	uudecode -p ${WRKSRC}/hello.adpcm.uu > ${PREFIX}/share/doc/adpcm/hello.adpcm

post-install:
	${STRIP_CMD} ${PREFIX}/lib/libadpcm.so.${LIBVERSION}

.include <bsd.port.mk>
