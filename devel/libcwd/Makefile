# ex:ts=8
# Ports collection makefile for:	libcwd
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcwd
PORTVERSION=	0.99.39
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The C++ Debugging Support Library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-threading
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
USE_GCC=	3.4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,test x"\$$libcwd_config_alloc" = x"yes",false,g' \
		-E -e 's,^(DEFS=)(.*),\1"\2 -D__GNU_LIBRARY__=yes",g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,localtime(,localtime((const time_t *),g' \
		${WRKSRC}/debugmalloc.cc
	@${REINPLACE_CMD} -E -e 's,\$$\(libdir\)/(pkgconfig),${PREFIX}/libdata/\1,g' \
		${WRKSRC}/${MAKEFILE}.in
	@${REINPLACE_CMD} -e 's,Elf32_Off,uint32_t,g' ${WRKSRC}/bfd.cc

.include <bsd.port.post.mk>
