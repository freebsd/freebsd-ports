PORTNAME=	libltdl
PORTREVISION=	0

COMMENT=	System independent dlopen wrapper

.include "${.CURDIR}/../libtool/Makefile.common"

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ltdl-install
INSTALL_TARGET=	install-strip
USES+=		libtool:keepla # .la file used in ltdl.m4
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	libltdl

.include <bsd.port.mk>
