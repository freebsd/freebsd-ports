# Created by: kuriyama
# $FreeBSD$

PORTNAME=	ipadic
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	SFJP/${PORTNAME}/24435

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Morphological Dictionary for ChaSen

BUILD_DEPENDS=	chasen:${PORTSDIR}/japanese/chasen-base
RUN_DEPENDS=	chasen:${PORTSDIR}/japanese/chasen-base

CONFIGURE_ARGS=	--with-dicdir=${PREFIX}/share/chasen/dic
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/chasenrc \
		${PREFIX}/share/chasen/dic/ipadic/chasenrc.example

.include <bsd.port.mk>
