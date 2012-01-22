# New ports collection makefile for:	graphite2
# Date created:		2012-01-22
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphite2
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	SF/silgraphite/${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	office@FreeBSD.org
COMMENT=	Rendering capabilities for complex non-Roman writing systems

USE_GNOME=	gnomehack
USE_CMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

post-patch:
	@${REINPLACE_CMD} -e 's,/pkgconfig,data/pkgconfig,g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,$${GRAPHITE_API_MAJOR}.$${GRAPHITE_API_MINOR}.$${GRAPHITE_API_AGE},$${GRAPHITE_API_MAJOR},g' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
