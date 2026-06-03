PORTNAME=	gravity
DISTVERSION=	0.9.7
CATEGORIES=	lang
PKGNAMESUFFIX=	-lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable programming language
WWW=		https://www.gravity-lang.org/ \
		https://marcobambini.github.io/gravity/ \
		https://github.com/marcobambini/gravity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c11 cpe
CPE_VENDOR=	creolabs
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	marcobambini

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
