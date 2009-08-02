# ex:ts=8
# Ports collection makefile for:	libcwd
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcwd
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C++ Debugging Support Library

USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--disable-threading --disable-pch --disable-location
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,test x"\$$libcwd_config_alloc" = x"yes",false,g' \
		-E -e 's,^(DEFS=)(.*),\1"\2 -D__GNU_LIBRARY__=yes",g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,localtime(,localtime((const time_t *),g' \
		-e 's,malloc\.h,stdlib.h,g' \
		${WRKSRC}/debugmalloc.cc
	@${REINPLACE_CMD} -E -e 's,\$$\(libdir\)/(pkgconfig),${PREFIX}/libdata/\1,g' \
		${WRKSRC}/${MAKEFILE}.in
	@${REINPLACE_CMD} -e 's,Elf32_Off,uint32_t,g' ${WRKSRC}/bfd.cc
	@${REINPLACE_CMD} -e 's|--tag=CXX||g' ${WRKSRC}/${MAKEFILE}.in \
		${WRKSRC}/utils/${MAKEFILE}.in

pre-configure:
	@${CP} ${LTMAIN} ${WRKSRC}

.include <bsd.port.mk>
