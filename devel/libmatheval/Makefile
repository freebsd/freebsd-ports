# New ports collection makefile for:	libmatheval
# Date created:				4 July 2004
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmatheval
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	devel math
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A library of procedures for evaluating mathematical functions

LIB_DEPENDS=	guile.19:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

INFO=		libmatheval

post-patch:
	${RM} ${WRKSRC}/doc/libmatheval.info

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
