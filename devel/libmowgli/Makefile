# New ports collection makefile for:	libmowgli
# Date Created:				06 Sep 2007
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmowgli
PORTVERSION=	0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A development framework for C

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|MOWGLI_DECLS_END   };|MOWGLI_DECLS_END   }|g' \
		${WRKSRC}/src/libmowgli/mowgli.h

.include <bsd.port.mk>
