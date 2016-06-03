# Created by: Ion-Mihai "IOnut" Tetcu<itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	libbnr
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	devel mail
MASTER_SITES=	http://dspam.nuclearelephant.com/sources/extras/ \
		http://T32.TecNik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	GPL implementation of the Bayesian Noise Reduction algorithm

OPTIONS_DEFINE=	DOCS DEBUG

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/${PORTNAME}

DEBUG_CFLAGS=	-g -DDEBUG

PORTDOCS=	README

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
