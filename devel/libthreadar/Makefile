PORTNAME=	libthreadar
PORTVERSION=	1.4.0
CATEGORIES=	devel sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/ \
		https://dar.edrusb.org/libthreadar/Releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Abstracted set of C++ *classes* to manipulate threads

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
