# $FreeBSD$

PORTNAME=	gravity
DISTVERSION=	0.5.9
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

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
