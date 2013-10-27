# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmatheval
PORTVERSION=	1.1.11
CATEGORIES=	devel math
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A library of procedures for evaluating mathematical functions

BUILD_DEPENDS=	flex>0:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes
USES=	pathfix
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-patch:
	${RM} ${WRKSRC}/doc/libmatheval.info

.include <bsd.port.mk>
