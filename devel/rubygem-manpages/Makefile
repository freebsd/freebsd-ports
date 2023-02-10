PORTNAME=	manpages
PORTVERSION=	0.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect man pages within gems and exposes them to the man command
WWW=		https://github.com/bitboxer/manpages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	rbenv/rbenv_hook_install.sh \
		rbenv/remove_hook_folders.sh

.include <bsd.port.mk>
