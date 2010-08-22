# New ports collection makefile for:	lensfun
# Date created:				Mon 25 May 2009 04:45:47 MSD
# Whom:					dindin@dindin.ru
#
# $FreeBSD$
#

PORTNAME=	lensfun
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fixing lens geometry distortion

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20
MAKEFILE=	GNUmakefile
LIBVERSION=	2

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CXXFLAGS+=	-I${LOCALBASE}/include

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS=	--prefix=${PREFIX} --target=${TARGET} --vectorization=SSE

PLIST_SUB+=	PORTVERSION=${PORTVERSION} LIBVERSION=${LIBVERSION}

post-patch:
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/python|#!/usr/bin/env python|' \
		-e 's|make --version|gmake --version|' \
		-e '/add_config_mak.*DOXYGEN/ d' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|{_libdir}/pkgconfig|{_libdir}/../libdata/pkgconfig|' \
		${WRKSRC}/build/lensfun.spec.in
	@${REINPLACE_CMD} -e 's|CONF_LIBDIR)pkgconfig|CONF_LIBDIR)../libdata/pkgconfig|g' \
		${WRKSRC}/build/tibs/compiler/pkgconfig.mak

post-install:
	@${LN} -sf ${PREFIX}/lib/lib${PORTNAME}.so ${PREFIX}/lib/lib${PORTNAME}.so.${LIBVERSION}

.include <bsd.port.mk>
