# New ports collection makefile for:	lensfun
# Date created:				Mon 25 May 2009 04:45:47 MSD
# Whom:					dindin@dindin.ru
#
# $FreeBSD$
#

PORTNAME=	lensfun
PORTVERSION=	0.2.3
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS

MAINTAINER=	dindin@dindin.ru
COMMENT=	Library for fixing lens geometry distortion

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20
MAKEFILE=	GNUmakefile

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CXXFLAGS+=	-I${LOCALBASE}/include

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS= --prefix=${PREFIX} --target=${TARGET}

post-patch:
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/python|#!/usr/bin/env python|' \
		-e 's|make --version|gmake --version|' \
		-e '/add_config_mak.*DOXYGEN/ d' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|cp -d|/bin/cp |' ${WRKSRC}/build/mak/host/posix.mak
	@${REINPLACE_CMD} -e 's|lib64|lib|' ${WRKSRC}/ac.py
	@${REINPLACE_CMD} \
		-e 's|$$(CONF_LIBDIR)pkgconfig/|$$(CONF_PREFIX)libdata/pkgconfig/|g'\
		${WRKSRC}/build/mak/compiler/pkgconfig.mak

.include <bsd.port.mk>
