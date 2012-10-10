# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	9.0
CATEGORIES=	converters ruby
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	Ruby wrapper for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	bsdconv:${PORTSDIR}/converters/bsdconv

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	ruby-${PORTNAME}
GH_COMMIT=	7bc3d11

.include <bsd.port.mk>
