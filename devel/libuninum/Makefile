# New ports collection makefile for:	libuninum
# Date created:		2007-01-07
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libuninum
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Library for converting Unicode strings to numbers

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
MAKE_ENV+=	INCLUDES="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

MAN1=		numconv.1

post-patch:
	${REINPLACE_CMD} -e 's|uninum/||' ${WRKSRC}/uninum.c ${WRKSRC}/numconv.c

.include <bsd.port.mk>
