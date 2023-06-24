PORTNAME=	libaudiofile
PORTVERSION=	0.3.6
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	GNOME/sources/${PORTNAME:S/lib//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for SGI audio file
WWW=		https://www.68k.org/~michael/audiofile/

LICENSE=	LGPL21

LIB_DEPENDS=	libFLAC.so:audio/flac

CONFLICTS=	osalp-0.7.*

USES=		cpe pathfix pkgconfig tar:xz libtool
CPE_PRODUCT=	audiofile
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/libaudiofile/modules/SimpleModule.h
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudiofile.so.1

.include <bsd.port.post.mk>
