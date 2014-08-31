# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swhplugins
PORTVERSION=	0.4.15
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/${PORTVERSION}/
DISTNAME=	swh-plugins-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steve Harris' huge Collection of LADSPA Plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	libfftw3f.so:${PORTSDIR}/math/fftw3-float

# includes assembler code
ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC -DPIC

OPTIONS_DEFINE=	NLS 3DNOW SSE
3DNOW_DESC=	use 3DNow! instructions
SSE_DESC=	use SSE instructions

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:M3DNOW}
CONFIGURE_ARGS+=	--enable-3dnow
.endif

.if ${PORT_OPTIONS:MSSE}
CONFIGURE_ARGS+=	--enable-sse
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|="$$CFLAGS -Wall .*"|="$$CFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g' ${WRKSRC}/ladspa-util.h

.include <bsd.port.mk>
