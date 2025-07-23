PORTNAME=	opus
DISTVERSION=	1.5.2
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	IETF audio codec
WWW=		https://opus-codec.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake libtool
CPE_VENDOR=	opus-codec
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-custom-modes \
		--enable-dred \
		--enable-osce \
		--disable-doc   # requires doxygen
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
