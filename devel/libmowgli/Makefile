# New ports collection makefile for:	libmowgli
# Date Created:				06 Sep 2007
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmowgli
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A development framework for C

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
