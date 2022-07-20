PORTNAME=	pygments.rb
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby wrapper for Pygments syntax highlighter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python:env shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	vendor/pygments-main/bin/pygmentize \
		lib/pygments/mentos.py
python_OLD_CMD=	/usr/bin/python3.9

.include <bsd.port.mk>
