# New ports collection makefile for:	mp3encode
# Date created:		5th August, 1998
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp3encode
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.sunet.se/pub/multimedia/Berkeley/mpeg2/conformance-bitstreams/audio/mpeg2/software/technical_report/
DISTNAME=	dist10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG layer I, II and III audio file encoder

RESTRICTED=	Condition is not clear

WRKSRC=		${WRKDIR}/${DISTNAME}/lsf/encoder

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	encode

# Directories and extra files
#
TABLE_LIB=	${PREFIX}/share/mp3encode
TABLE_LIB_SED=	${TABLE_LIB:S/\//\\\//g}
TABLE_FILES=	1cb0 1cb1 1cb2 1cb4 1cb5 1cb6 1th0 1th1 1th2 1th4 1th5 1th6 \
		2cb0 2cb1 2cb2 2cb4 2cb5 2cb6 2th0 2th1 2th2 2th4 2th5 2th6 \
		absthr_0 absthr_1 absthr_2 alloc_0 alloc_1 alloc_2 alloc_3 \
		alloc_4 dewindow enwindow huffcode huffdec psy_data

post-patch:
	@${ECHO_MSG} "===>  Specifing table path "
	${SED} "s/ZAP/${TABLE_LIB_SED}/g" < ${WRKSRC}/common.h >${WRKSRC}/common.h.sed
	${CP} -f ${WRKSRC}/common.h.sed ${WRKSRC}/common.h

do-install:
	@${ECHO_MSG} "===>  Installing binaries"
	${INSTALL_PROGRAM} ${WRKSRC}/encode ${PREFIX}/bin
	@${ECHO_MSG} "===>  Installing table files"
	-${MKDIR} ${TABLE_LIB}
.for file in ${TABLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/tables/${file} ${TABLE_LIB}
.endfor

.include <bsd.port.mk>
