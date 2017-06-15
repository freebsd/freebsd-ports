# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swhplugins
PORTVERSION=	0.4.15
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/${PORTVERSION}/
DISTNAME=	swh-plugins-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steve Harris' huge Collection of LADSPA Plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

# includes assembler code
ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC -DPIC

OPTIONS_DEFINE=	NLS 3DNOW SSE
OPTIONS_SUB=	yes
3DNOW_DESC=	use 3DNow! instructions
SSE_DESC=	use SSE instructions

NLS_USES=	gettext
NLS_LDFLAGS=	-lintl
NLS_CONFIGURE_ENABLE=	nls

3DNOW_CONFIGURE_ENABLE=	3dnow

SSE_CONFIGURE_ENABLE=	sse

post-patch:
	@${REINPLACE_CMD} -e \
		's|="$$CFLAGS -Wall .*"|="$$CFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g' ${WRKSRC}/ladspa-util.h

.include <bsd.port.mk>
