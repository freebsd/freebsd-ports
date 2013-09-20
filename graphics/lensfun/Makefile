# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	lensfun
PORTVERSION=	0.2.7
CATEGORIES=	graphics
MASTER_SITES=	SF/lensfun.berlios

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fixing lens geometry distortions

LICENSE=	LGPL3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USES=		pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes

MAKEFILE=	GNUmakefile
LIBVERSION=	2

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LD="${CXX}" AR="${AR}"
CONFIGURE_ARGS=	--prefix=${PREFIX} --target=${TARGET} --vectorization=SSE
MAKE_ARGS=	V=1	# we want to know what's going on during the build

PLIST_SUB+=	LIBVERSION=${LIBVERSION}

post-patch: .SILENT
	${REINPLACE_CMD} -e '1s|#!/usr/bin/python|#!/usr/bin/env python|' \
		-e 's|make --version|g&|' -e '/DOXYGEN/d' ${WRKSRC}/configure
	${REINPLACE_CMD} -e \
		's|CONF_LIBDIR)pkgconfig|CONF_LIBDIR)../libdata/pkgconfig|' \
			${WRKSRC}/build/tibs/compiler/pkgconfig.mak
	${REINPLACE_CMD} -e '/-s -O3/d' -e '/LDFLAGS\.r/s|-s|${STRIP}|' \
		${WRKSRC}/build/tibs/compiler/gcc.mak
	${REINPLACE_CMD} -e '/GROUPS/s| DOCS||' ${WRKSRC}/build/tibs/rules.mak

NO_STAGE=	yes
post-install:
	${LN} -sf lib${PORTNAME}.so \
		${PREFIX}/lib/lib${PORTNAME}.so.${LIBVERSION}

.include <bsd.port.mk>
