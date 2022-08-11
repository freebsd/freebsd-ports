PORTNAME=	libgpc
PORTVERSION=	2.32
CATEGORIES=	devel math graphics
MASTER_SITES=	http://www.cs.man.ac.uk/~toby/alan/software/assets/
DISTNAME=	gpc${PORTVERSION:S/.//}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Generic Polygon Clipper

# Converted from NO_CDROM
LICENSE=	libgpc
LICENSE_NAME=	libgpc
LICENSE_TEXT=	Can't be used for profit without permission
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		dos2unix uidfix zip
PLIST_FILES=	lib/libgpc.so.2	\
		lib/libgpc.so	lib/libgpc.a	\
		include/gpc.h
USE_LDCONFIG=	yes

MAKEFILE=	${FILESDIR}/BSDmakefile

.include <bsd.port.mk>
