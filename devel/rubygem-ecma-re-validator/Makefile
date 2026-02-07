PORTNAME=	ecma-re-validator
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Regular expression validator against ECMA-262
WWW=		https://github.com/gjtorikian/ecma-re-validator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-regexp_parser>=2.0<3:textproc/rubygem-regexp_parser

USES=		gem shebangfix

SHEBANG_FILES=	script/bootstrap

NO_ARCH=	yes

.include <bsd.port.mk>
