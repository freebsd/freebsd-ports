# New ports collection makefile for:	mppdec
# Date created:				2002-12-28
# Whom:					Stefan Ehmann <shoesoft@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	mppdec
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.personal.uni-jena.de/~pfk/MPP/src/ \
		http://stud4.tuwien.ac.at/~e0125637/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Command-line player/decoder for musepack audio

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound

MAKEFILE=	Makefile.bsd
PLIST_FILES=	bin/mppdec
USE_BZIP2=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

post-patch:
.if ${ARCH} != i386
		${REINPLACE_CMD} -e "s,#define USE_ASM,//define USE_ASM," ${WRKSRC}/mpp.h
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mppdec ${PREFIX}/bin/

.include <bsd.port.post.mk>
