# New ports collection makefile for:	libmng
# Date created:		Nov 2, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libmng
PORTVERSION=	1.0.10
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION} \
		http://www.libmng.com/download/


MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multiple-image Network Graphics (MNG) reference library

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms

OPTIONS=	MNG_OPTIMIZE "Use vendor's new optimization flags" off

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	WITH_MNG_OPTIMIZE=${WITH_MNG_OPTIMIZE}
MAKE_JOBS_SAFE=	yes
#USE_BZIP2=	yes	# Please, uncomment on next upgrade

USE_LDCONFIG=	yes

MAN3=		libmng.3
MAN5=		mng.5 jng.5

post-install:
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3 \
		&& ${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5

.include <bsd.port.mk>
