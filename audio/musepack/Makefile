PORTNAME=	musepack
PORTVERSION=	2011.08.10
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/source/
DISTNAME=	${PORTNAME}_src_r475

MAINTAINER=	shoesoft@gmx.net
COMMENT=	Decoder, encoder, and replaygain for musepack (mpc)
WWW=		https://www.musepack.net/

LICENSE=	BSD3CLAUSE GPLv2+ LGPL21+
LICENSE_COMB=	multi

DEPRECATED=	Legacy format that never got traction and no development in over a decade, consider using multimedia/ffmpeg for decoding
EXPIRATION_DATE=2024-09-30

USES=		autoreconf libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
