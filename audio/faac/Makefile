PORTNAME=	faac
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.50
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ecd5a10122a9ce698516bb587b6036efab0a787d.patch:-p1 # disables LTO, breaks static lib

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder
WWW=		https://github.com/knik0/faac

LICENSE=		GPLv3+ ISO LGPL21+
LICENSE_COMB=		multi
LICENSE_NAME_ISO=	ISO/IEC14496
LICENSE_FILE_ISO=	${WRKSRC}/README
LICENSE_PERMS_ISO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler:c11 meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	knik0

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
