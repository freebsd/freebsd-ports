# New ports collection makefile for:	xvid
# Date created:		04 April 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net> et al
#
# $FreeBSD$
#

PORTNAME=	xvid
PORTVERSION=	0.20020412
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xvid.org/snapshots/
DISTNAME=	xvid_snapshot_${PORTVERSION:S/^0.//}

MAINTAINER=	michaelnottebrock@gmx.net

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386
USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_WRKSRC=	${WRKDIR}
WRKSRC=			${WRKDIR}/xvid_20020412/xvidcore/build/generic

# XXX - compatility header installed for mplayer-devel port's benefit
EXTRA_HEADER_FILES=	divx4.h

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@ ${ECHO_MSG} "You can enable additional compilation optimizations"
	@ ${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@ ${FIND} ${WRKDIR} -type f | \
		${XARGS} -n 10 -x ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|'
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@ ${REINPLACE_CMD} -E -e 's|(CFLAGS \+=).*|\1 ${CFLAGS}|' ${WRKSRC}/Makefile
.else
	@ ${REINPLACE_CMD} -E -e 's|(CFLAGS \+=.*)|\1 ${CFLAGS}|' ${WRKSRC}/Makefile
.endif

# trick to detect existence of stdint.h
pre-configure:
.for file in configure.in config.h.in
	@ ${CP} ${FILESDIR}/${file} ${WRKDIR}
.endfor

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libxvidcore.so ${PREFIX}/lib/libxvidcore.so.0
	@ ${INSTALL_DATA} ${WRKSRC}/libcore.a ${PREFIX}/lib/libcore.a
	@ ${LN} -s libxvidcore.so.0 ${PREFIX}/lib/libxvidcore.so
	@ ${INSTALL_DATA} ${WRKSRC}/../../src/xvid.h ${PREFIX}/include
# XXX - compatility header installed for mplayer-devel port's benefit
	@ ${MKDIR} ${PREFIX}/include/xvid
.for header in ${EXTRA_HEADER_FILES}
	@ ${INSTALL_DATA} ${WRKSRC}/../../src/${header} ${PREFIX}/include/xvid
.endfor

.include <bsd.port.mk>
