# New ports collection Makefile for: 	swhplugins
# Date created:			12 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	swhplugins
PORTVERSION=	0.4.14
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	swh-plugins-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steve Harris' huge Collection of LADSPA Plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	fftw3f.4:${PORTSDIR}/math/fftw3-float

# includes assembler code
ONLY_FOR_ARCHS=	i386 amd64

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

CFLAGS+=	-fPIC -DPIC

.if defined(WITH_3DNOW)
CONFIGURE_ARGS+=	--enable-3dnow
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|="$$CFLAGS -Wall .*"|="$$CFLAGS"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<stdint\.h>|<inttypes.h>|g' ${WRKSRC}/ladspa-util.h

.include <bsd.port.mk>
