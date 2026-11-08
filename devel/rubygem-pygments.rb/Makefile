PORTNAME=	pygments.rb
PORTVERSION=	5.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby wrapper for Pygments syntax highlighter
WWW=		https://github.com/pygments/pygments.rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-logger>=1.7<2:devel/rubygem-logger

USES=		gem python:env shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	vendor/pygments-main/bin/pygmentize \
		lib/pygments/mentos.py
python_OLD_CMD=	.*python.*

.include <bsd.port.mk>
