# New ports collection Makefile for:   cmt
# Date created:                        11 May 2002
# Whom:                                Tilman Linneweh <freebsdports@arved.de
#
# $FreeBSD$

PORTNAME=	cmt
PORTVERSION=	1.12
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	${PORTNAME}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsdports@arved.de

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	makefile
ALL_TARGET=	targets

post-patch:
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} ${PERL} -pi -e \
		's|<malloc.h>|<stdlib.h>|g'

.for i in ${WRKSRC}/analogue.cpp \
	${WRKSRC}/canyondelay.cpp \
	${WRKSRC}/lofi.cpp \
	${WRKSRC}/phasemod.cpp \
	${WRKSRC}/syndrum.cpp \
	${WRKSRC}/vcf303.cpp
	${MV} ${WRKDIR}/$i ${WRKDIR}/$i.sed
	${SED} -e "s:malloc.h:stdlib.h:g" \
		${WRKDIR}/$i.sed >${WRKDIR}/$i
	${RM} ${WRKDIR}/$i.sed
.endfor

do-install:
	@${INSTALL_DATA} ${WRKSRC}/../plugins/cmt.so ${LOCALBASE}/lib/ladspa/

.include <bsd.port.mk>
