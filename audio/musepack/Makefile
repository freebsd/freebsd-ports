# New ports collection makefile for:	musepack
# Date created:				2004-04-16
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	musepack
PORTVERSION=	1.15v
CATEGORIES=	audio
MASTER_SITES=	http://www.saunalahti.fi/grimmel/musepack.net-files/source/
DISTNAME=	mpcsv7-src-${PORTVERSION}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Decoder, encoder and replaygain for musepack (mpc)

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound

PLIST_FILES=	bin/mppdec bin/mppenc bin/replaygain
BINS=		mppdec mppenc replaygain
ALL_TARGET=	${BINS}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/sv7

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

post-patch:
.if ${ARCH} != i386
	${REINPLACE_CMD} -e "s|#define USE_ASM|//#define USE_ASM|" ${WRKSRC}/mpp.h
.endif
	${REINPLACE_CMD} -e "s|#define USE_IRIX_AUDIO|//#define USE_IRIX_AUDIO|" ${WRKSRC}/mpp.h
	${REINPLACE_CMD} -e "s|<machine/soundcard.h>|<sys/soundcard.h>|" ${WRKSRC}/mppdec.h

do-install:
.for _BIN in ${BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${_BIN} ${LOCALBASE}/bin
.endfor

.include <bsd.port.post.mk>
