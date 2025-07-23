PORTNAME=	libogg
DISTVERSION=	1.3.6
PORTEPOCH=	4
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/ogg/ \
		https://github.com/xiph/ogg/releases/download/v${DISTVERSION}/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Ogg bitstream library
WWW=		https://www.xiph.org/ogg/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
