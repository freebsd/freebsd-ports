# New ports collection makefile for:	svgalib
# Date created:				24 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	svgalib
PORTVERSION=	1.4.3
PORTREVISION=	5
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.svgalib.org/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A low level console graphics library

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MANCOMPRESSED=	yes

ALL_TARGET=	shared static

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.for i in 1 2 3 4 5 6 7 8 9
.if exists(${FILESDIR}/man${i})
MAN${i}!=	${CAT} ${FILESDIR}/man${i}
.endif
.endfor

pre-patch:
	for file in ${WRKSRC}/utils/gtf/*.h; do \
		${TR} -d '\015' < $${file} > $${file}.new; \
		${MV} $${file}.new $${file}; \
	done
	${MKDIR} ${WRKSRC}/include/linux

post-install:
	${MKDIR} ${PREFIX}/include/linux
	cd ${WRKSRC}/include/linux && \
		${INSTALL_DATA} keyboard.h kd.h ${PREFIX}/include/linux

.include <bsd.port.post.mk>
