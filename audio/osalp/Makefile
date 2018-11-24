# Created by: ijliao
# $FreeBSD$

PORTNAME=	osalp
PORTVERSION=	0.7.5
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}-beta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Audio Library Project

RUN_DEPENDS=	mpg123:audio/mpg123
LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libvorbis.so:audio/libvorbis

USES=		libtool localbase:ldflags
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-all

CFLAGS+=	-fPIC -DPIC

USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

CONFLICTS=	libaudiofile-[0-9]*

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -E \
	    's|iostream.h|iostream|; \
	     s|[[:space:]]cout| std::cout|g; \
	     s|[[:space:]]endl| std::endl|g; \
	     s|[[:space:]]cerr| std::cerr|g;'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaflib-${PORTVERSION}.so \
	    ${STAGEDIR}${PREFIX}/lib/aflib/lib*-${PORTVERSION}.so

.include <bsd.port.mk>
