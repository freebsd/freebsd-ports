# $FreeBSD$

PORTNAME=	gravity
DISTVERSION=	0.7.9
CATEGORIES=	lang
PKGNAMESUFFIX=	-lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable programming language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	marcobambini

PLIST_FILES=	bin/${PORTNAME} \
		lib/libgravityapi.so \
		lib/libgravityapi_s.a

.include <bsd.port.mk>
