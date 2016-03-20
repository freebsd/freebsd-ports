# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s2tc
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	S2TC is a subset of a wellknown texture compression scheme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	divVerent
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
