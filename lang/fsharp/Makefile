# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	fsharp
PORTVERSION=	3.0.25
CATEGORIES=	lang
MASTER_SITES=	https://nodeload.github.com/fsharp/fsharp/tar.gz/ \
		CRITICAL
DISTFILES=	${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Functional and object-oriented language for the .NET platform
LICENSE=	AL2

BUILD_DEPENDS=	mono>=3.0:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono>=3.0:${PORTSDIR}/lang/mono

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_PKGCONFIG=	build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
