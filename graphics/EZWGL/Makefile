# New ports collection makefile for:	EZWGL
# Version required:			1.40
# Date created:				4 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	EZWGL-1.40c
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	EZWGL-1.40-doc.tgz ${DISTNAME}-src.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

ALL_TARGET=	shared clean static
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

.include "files/manpages"

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	1
.else
VERSION=	1.4
.endif

pre-install:
.for file in Makefile.orig animate btnbox clock counter hanoi locator meter puzzle
	-@ ${RM} ${WRKSRC}/demos/${file}
.endfor
.for file in Makefile.orig src1 src2 target1 target2
	-@ ${RM} ${WRKSRC}/demos/DnD/${file}
.endfor
.for file in setroot transparent
	-@ ${RM} ${WRKSRC}/demos/Glass/${file}
.endfor
.for file in Makefile.orig gears image julia pendulum
	-@ ${RM} ${WRKSRC}/demos/GL/${file}
.endfor
.for file in Makefile.orig client server
	-@ ${RM} ${WRKSRC}/demos/Message/${file}
.endfor
	-@ ${RMDIR} ${WRKDIR}/EZWGL-1.40/doc/html/misc
	-@ ${MV} ${WRKDIR}/EZWGL-1.40/doc/man3/EZ_RegisterCompositeWidget,3 ${WRKDIR}/EZWGL-1.40/doc/man3/EZ_RegisterCompositeWidget.3
	-@ ${RM} ${WRKSRC}/examples/Makefile.orig

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/include/EZ.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.so.${VERSION} ${PREFIX}/lib
	@ ${LN} -sf libEZ.so.${VERSION} ${PREFIX}/lib/libEZ.so
.for file in ${MAN3}
	@ ${INSTALL_MAN} ${WRKDIR}/EZWGL-1.40/doc/man3/${file} ${PREFIX}/man/man3
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/EZ
	@ cd ${WRKSRC}/examples; tar cf - * | \
		(cd ${PREFIX}/share/examples/EZ; tar --unlink -xf - )
	@ ${MKDIR} ${PREFIX}/share/examples/EZ/demos
	@ cd ${WRKSRC}/demos; tar cf - * | \
		(cd ${PREFIX}/share/examples/EZ/demos; tar --unlink -xf - )

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/EZ
	@ cd ${WRKDIR}/EZWGL-1.40/doc; tar cf - html ps | \
		(cd ${PREFIX}/share/doc/EZ; tar --unlink -xf - )
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
