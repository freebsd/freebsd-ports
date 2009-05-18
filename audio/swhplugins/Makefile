# New ports collection Makefile for: 	swhplugins
# Date created:			12 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	swhplugins
PORTVERSION=	0.4.15
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	swh-plugins-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steve Harris' huge Collection of LADSPA Plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	fftw3f.5:${PORTSDIR}/math/fftw3-float

# includes assembler code
ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC -DPIC

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
.endif

OPTIONS=	3DNOW "use 3DNow! instructions" off \
		SSE "use SSE instructions" off

.include <bsd.port.pre.mk>

.if defined(WITH_3DNOW)
CONFIGURE_ARGS+=	--enable-3dnow
.endif

.if defined(WITH_SSE)
CONFIGURE_ARGS+=	--enable-sse
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|="$$CFLAGS -Wall .*"|="$$CFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g' ${WRKSRC}/ladspa-util.h

.include <bsd.port.post.mk>
