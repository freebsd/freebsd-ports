# New ports collection makefile for:    Mesa for Linux compat
# Version required:     2.6
# Date created:         Oct, 8 1998
# Whom:                 cracauer
#
# $Id: Makefile,v 1.3 1998/11/05 11:39:51 cracauer Exp $
#

DISTNAME=       MesaLib-2.6
PKGNAME=	linux_mesa-2.6
CATEGORIES=	emulators
MASTER_SITES= 	ftp://iris.ssec.wisc.edu/pub/Mesa/old-versions/

MAINTAINER=	cracauer@cons.org

BUILD_DEPENDS=	/compat/linux/usr/lib/libglide2x.so:${PORTSDIR}/emulators/linux_glide \
		/compat/linux/usr/bin/gcc:${PORTSDIR}/devel/linux_devel

ONLY_FOR_ARCHS=	i386

ALL_TARGET=	linux-glide
MAKE_ENV=	PATH=${PREFIX}/usr/bin:$$PATH
NO_FILTER_SHLIBS=yes

PREFIX=		/compat/linux
WRKSRC=		${WRKDIR}/Mesa-2.6/src

post-extract:
	-${MKDIR} ${WRKSRC}/../lib/

do-install:
	${INSTALL_DATA} ${WRKSRC}/../lib/libMesaGL.so.2.6 ${PREFIX}/usr/lib/.
	${LN} -fs libMesaGL.so.2.6 ${PREFIX}/usr/lib/libMesaGL.so.2
	${LN} -fs libMesaGL.so.2.6 ${PREFIX}/usr/lib/libMesaGL.so
	${LN} -fs libMesaGL.so.2.6 ${PREFIX}/usr/lib/libGL.so
	@${MKDIR} ${PREFIX}/usr/include/GL
	${INSTALL_DATA} ${WRKSRC}/../include/GL/* ${PREFIX}/usr/include/GL/.
	${INSTALL_DATA} ${WRKSRC}/../include/glaux.h ${PREFIX}/usr/include/.
	${INSTALL_DATA} ${WRKSRC}/../include/gltk.h ${PREFIX}/usr/include/.
	-/compat/linux/sbin/ldconfig

.include <bsd.port.mk>
