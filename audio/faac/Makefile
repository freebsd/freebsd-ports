PORTNAME=	faac
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.31.1
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder
WWW=		https://github.com/knik0/faac

LICENSE=		GPLv3+ ISO LGPL21+
LICENSE_COMB=		multi
LICENSE_NAME_ISO=	ISO/IEC14496
LICENSE_FILE_ISO=	${WRKSRC}/README
LICENSE_PERMS_ISO=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Produces poor audio quality compared to other encoders, consider using audio/fdk-aac , audio/exhale (xHE-AAC which supersedes AAC-LC) or FFmpeg's native encoder
EXPIRATION_DATE=2025-04-30

USES=		autoreconf compiler:c11 gmake libtool pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	knik0

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
