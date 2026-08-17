PORTNAME=	lndir
DISTVERSION=	1.0.6
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Create a shadow directory of symbolic links to another directory tree
WWW=		https://gitlab.freedesktop.org/xorg/util/lndir/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:util
USE_XORG=	xorgproto

PLIST_FILES=	bin/lndir \
		share/man/man1/lndir.1.gz

.include <bsd.port.mk>
