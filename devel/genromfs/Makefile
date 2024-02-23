PORTNAME=	genromfs
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tomek@cedro.info
COMMENT=	Mkfs equivalent for romfs filesystem
WWW=		https://github.com/chexum/genromfs

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	chexum

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES=	bin/genromfs \
		share/man/man8/genromfs.8.gz

.include <bsd.port.mk>
