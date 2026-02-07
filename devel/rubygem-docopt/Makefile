PORTNAME=	docopt
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse command line arguments based on nothing more than a usage message
WWW=		https://github.com/docopt/docopt.rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python:env shebangfix

SHEBANG_FILES=	test/language_agnostic_tester.py

NO_ARCH=	yes

.include <bsd.port.mk>
