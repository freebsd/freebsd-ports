PORTNAME=	wimlib
DISTVERSION=	1.14.4
CATEGORIES=	filesystems sysutils
MASTER_SITES=	https://wimlib.net/downloads/

MAINTAINER=	mail_of_sergey@mail.ru
COMMENT=	Manipulate Windows Imaging (WIM) archives
WWW=		https://wimlib.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv3

USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NTFS
OPTIONS_DEFAULT=	NTFS

NTFS_DESC=		Build with libntfs-3g for NTFS support (recommended)

NTFS_LIB_DEPENDS=	libntfs-3g.so:filesystems/ntfs
NTFS_CONFIGURE_WITH=	ntfs-3g

.include <bsd.port.mk>
