PORTNAME=	faac
PORTVERSION=	1.30
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder

LICENSE=	GPLv2 LGPL21+ ISO
LICENSE_COMB=	multi
LICENSE_NAME_ISO=	ISO/IEC14496
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_ISO=	${WRKSRC}/README
LICENSE_PERMS_ISO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf compiler:c11 gmake libtool
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	knik0
GH_TAGNAME=	78d8e01

.include <bsd.port.mk>
