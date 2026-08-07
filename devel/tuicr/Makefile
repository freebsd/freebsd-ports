PORTNAME=	tuicr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Code review TUI with Vim keybindings
WWW=		https://github.com/agavra/tuicr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma \
		libssh2.so:security/libssh2

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	agavra

PLIST_FILES=	bin/tuicr

.include <bsd.port.mk>
