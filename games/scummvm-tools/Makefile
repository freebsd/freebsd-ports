# New ports collection makefile for:	scummvm-tools
# Date created:				28 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scummvm-tools
PORTVERSION=	0.7.0
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scummvm

MAINTAINER=	alexander@trull.com
COMMENT=	Tools for use with the SCUMMVM game emulator

RUN_DEPENDS=	scummvm:${PORTSDIR}/games/scummvm
BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		oggdec:${PORTSDIR}/audio/vorbis-tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BUILD_DEPENDS+= gcc32:${PORTSDIR}/lang/gcc32
.endif

do-install:
.for i in descumm extract md5table mm_nes_extract queenrebuild rescumm
	@${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's@:= -g -O@+= ${CFLAGS}@' ${WRKSRC}/Makefile
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's/gcc/gcc32/g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's/g\+\+/g\+\+32/g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
