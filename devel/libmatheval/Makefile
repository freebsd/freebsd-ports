# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmatheval
PORTVERSION=	1.1.11
PORTREVISION=	2
CATEGORIES=	devel math
MASTER_SITES=	GNU

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library to evaluate mathematical functions

BUILD_DEPENDS=	flex>=2.5.39_1:textproc/flex
LIB_DEPENDS=	libguile.so:lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LEXLIB=-lfl_pic MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes
USES=		libtool localbase makeinfo pathfix
INSTALL_TARGET=	install-strip

INFO=		libmatheval

post-patch:
	${RM} ${WRKSRC}/doc/libmatheval.info

.include <bsd.port.mk>
