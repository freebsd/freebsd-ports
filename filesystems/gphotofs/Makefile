PORTNAME=	gphotofs
DISTVERSION=	0.5.20181029
CATEGORIES=	filesystems graphics sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Mount PTP camera as a file system
WWW=		https://github.com/gphoto/gphotofs

LICENSE=	GPLv2

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		autoreconf fuse gnome libtool pkgconfig
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	gphoto
GH_TAGNAME=	9f9f594

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gphotofs

.include <bsd.port.mk>
