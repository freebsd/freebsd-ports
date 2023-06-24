PORTNAME=	libtremor
PORTVERSION=	1.2.1.s20180319
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integer-only fully Ogg Vorbis compliant decoder library
WWW=		https://xiph.org/vorbis/

DEPRECATED=	Obsolete, we only support hardware with a fpu and other decoding libraries offer better performance 
EXPIRATION_DATE=2023-09-30

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		autoreconf libtool pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.xiph.org
GL_ACCOUNT=	xiph
GL_PROJECT=	tremor
GL_COMMIT=	7c30a66346199f3f09017a09567c6c8a3a0eedc8

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
