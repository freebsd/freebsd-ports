PORTNAME=	libthreadar
DISTVERSION=	1.6.1
CATEGORIES=	devel sysutils
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION}/ \
		https://dar.edrusb.org/libthreadar/Releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Abstracted set of C++ *classes* to manipulate threads
WWW=		https://libthreadar.sourceforge.net/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	SOLIB_MINOR=${DISTVERSION:S/1.//}

.include <bsd.port.mk>
