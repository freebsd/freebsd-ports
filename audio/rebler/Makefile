# ex:ts=8
# New ports collection makefile for:	rebler
# Date created:			Nov 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rebler
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to convert mpeg2 and ac3 into DivX with ac3 audio

LIB_DEPENDS=	mpeg2:${PORTSDIR}/multimedia/libmpeg2 \
		aviplay.0:${PORTSDIR}/multimedia/avifile \
		popt:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
AVIFILE_CONFIG?=	${LOCALBASE}/bin/avifile-config
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		`${AVIFILE_CONFIG} --cflags`
LIBS+=		-L${LOCALBASE}/lib -lm -lmpeg2 ${PTHREAD_LIBS} \
		`${AVIFILE_CONFIG} --libs` -lpopt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

do-build:
	@(cd ${WRKSRC} ; \
	  ${CXX} ${CXXFLAGS} rebler.cpp -o rebler ${LIBS})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rebler ${PREFIX}/bin

.include <bsd.port.post.mk>
