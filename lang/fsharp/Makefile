# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	fsharp
PORTVERSION=	3.1.1.25
CATEGORIES=	lang

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Functional and object-oriented language for the .NET platform

LICENSE=	APACHE20

BROKEN=		Fails to build with mono 4

BUILD_DEPENDS=	mono>=3.0:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono>=3.0:${PORTSDIR}/lang/mono

USE_GITHUB=	yes

USES=		gmake mono pkgconfig
USE_AUTOTOOLS=	autoconf

.include <bsd.port.mk>
