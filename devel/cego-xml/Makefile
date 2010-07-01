# New ports collection makefile for:	cego-xml
# Date created:				Jun 12, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	cego-xml
PORTVERSION=	1.0.20
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/
DISTNAME=	xml-${PORTVERSION}

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	C++ XML library, used for databases/cego

LIB_DEPENDS=	Base.1:${PORTSDIR}/devel/cego-base

LICENSE=	GPLv2
WRKSRC=		${WRKDIR}/xml
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:262:env

.include <bsd.port.mk>
