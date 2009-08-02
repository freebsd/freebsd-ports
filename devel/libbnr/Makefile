# New ports collection makefile for:	libbnr
# Date created:				2005-02-27
# Whom:			Ion-Mihai "IOnut" Tetcu<itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	libbnr
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	devel mail
MASTER_SITES=	http://dspam.nuclearelephant.com/sources/extras/ \
		http://T32.TecNik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	GPL implementation of the Bayesian Noise Reduction algorithm

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/${PORTNAME}

.ifdef(WITH_DEBUG)
CFLAGS+=	-g -DDEBUG
.endif

PORTDOCS=	README

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
