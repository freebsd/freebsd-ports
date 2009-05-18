# New ports collection makefile for:	aacplusenc
# Date created:				28 July 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aacplusenc
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://teknoraver.net/software/mp4tools/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	aacPlus v2 command-line encoder

USE_BZIP2=	yes
USE_GMAKE=	yes

RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

PLIST_FILES=	bin/aacplusenc

.if defined(WITHOUT_FFTW3)
MAKE_ARGS+=	NOFFTW3=1
.else
LIB_DEPENDS+=	fftw3f.5:${PORTSDIR}/math/fftw3-float \
		fftw3.5:${PORTSDIR}/math/fftw3
CFLAGS+=	-I${LOCALBASE}/include
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -ftree-vectorize|${CFLAGS}| ; s|-lfftw3f|-L${LOCALBASE}/lib -lfftw3f|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<endian.h>|<sys/endian.h>| ; s|__BYTE|_BYTE|' ${WRKSRC}/au_channel.h

.include <bsd.port.mk>
