# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	fsharp
PORTVERSION=	3.0.34
CATEGORIES=	lang

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Functional and object-oriented language for the .NET platform

LICENSE=	APACHE20

BUILD_DEPENDS=	mono>=3.0:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono>=3.0:${PORTSDIR}/lang/mono

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	b0c16bb

USES=		gmake pkgconfig
USE_AUTOTOOLS=	autoconf

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
