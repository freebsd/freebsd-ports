# Created by: kuriyama
# $FreeBSD$

PORTNAME=	ipadic
PORTVERSION=	2.7.0
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	SFJP/${PORTNAME}/24435

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Dictionary for ChaSen

BUILD_DEPENDS=	chasen:japanese/chasen-base
RUN_DEPENDS=	chasen:japanese/chasen-base

CONFIGURE_ARGS=	--with-dicdir=${PREFIX}/share/chasen/dic \
		--with-chasenrc-path=${STAGEDIR}${PREFIX}/share/chasen/dic/ipadic
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/chasen/dic/ipadic
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
	    ${STAGEDIR}${PREFIX}/share/chasen/dic/ipadic/chasenrc.sample

.include <bsd.port.mk>
