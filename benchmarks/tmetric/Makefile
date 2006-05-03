# New ports collection makefile for:	tmetric
# Date created:				June 5th 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	tmetric
PORTVERSION=	v0.6
PORTEPOCH=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://michael.bacarella.com/projects/tmetric/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bandwidth measurement tool

HAS_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
PLIST_FILES=	sbin/tmetric
USE_BZIP2=	yes

MAN8=		tmetric.8

post-patch:
	@${REINPLACE_CMD} -e 's%/usr/local%${PREFIX}%' ${WRKSRC}/*

.include <bsd.port.mk>
