# $FreeBSD$

PORTNAME=	gravity
DISTVERSION=	0.8.0
CATEGORIES=	lang
PKGNAMESUFFIX=	-lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable programming language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marcobambini

PLIST_FILES=	bin/${PORTNAME} \
		lib/libgravityapi.so \
		lib/libgravityapi_s.a

.include <bsd.port.mk>
