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
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/libbnr/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	GPL implementation of the Bayesian Noise Reduction algorithm

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
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
