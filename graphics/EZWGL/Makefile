# New ports collection makefile for:	EZWGL
# Version required:			1.40
# Date created:				4 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.13 1998/11/21 07:27:35 steve Exp $
#

DISTNAME=	EZWGL-1.40
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	${DISTNAME}-demo.tgz ${DISTNAME}-doc.tgz ${DISTNAME}-src.tgz

MAINTAINER=	andy@icc.surw.chel.su

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
	-@ ${RM} ${WRKSRC}/demos/Makefile.orig
	-@ ${RM} ${WRKSRC}/demos/DnD/Makefile.orig
	-@ ${RM} ${WRKSRC}/demos/GL/Makefile.orig
	-@ ${RM} ${WRKSRC}/demos/Message/Makefile.orig
	-@ ${MV} ${WRKSRC}/doc/man3/EZ_RegisterCompositeWidget,3 ${WRKSRC}/doc/man3/EZ_RegisterCompositeWidget.3
	-@ ${RM} ${WRKSRC}/examples/Makefile.orig

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/include/EZ.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.so.${VERSION} ${PREFIX}/lib
	@ ${LN} -sf libEZ.so.${VERSION} ${PREFIX}/lib/libEZ.so
.for file in ${MAN3}
	@ ${INSTALL_MAN} ${WRKSRC}/doc/man3/${file} ${PREFIX}/man/man3
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
	@ cd ${WRKSRC}/doc; tar cf - html ps | \
		(cd ${PREFIX}/share/doc/EZ; tar --unlink -xf - )
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
