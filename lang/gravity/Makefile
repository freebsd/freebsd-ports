# $FreeBSD$

PORTNAME=	gravity
DISTVERSION=	0.6.1
CATEGORIES=	lang
PKGNAMESUFFIX=	-lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable programming language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	marcobambini

LDFLAGS+=	-lm

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
