# New ports collection makefile for:	EZWGL
# Version required:			1.39
# Date created:				4 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.10 1998/09/19 01:36:18 hoek Exp $
#

DISTNAME=	EZWGL-1.39
CATEGORIES=	graphics devel x11
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	${DISTNAME}-src.tgz ${DISTNAME}-doc.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

ALL_TARGET=	shared clean static
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

.include "files/manpages"

pre-install:
	-@ ${RM} ${WRKSRC}/examples/Makefile.orig
	-@ ${RM} ${WRKSRC}/examples/ExampleMsg

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/include/EZ.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.so.${VERSION} ${PREFIX}/lib
	@ ${LN} -sf libEZ.so.${VERSION} ${PREFIX}/lib/libEZ.so
.for file in ${MAN3}
	@ ${INSTALL_MAN} ${WRKSRC}/man3/${file} ${PREFIX}/man/man3
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/EZ/pixmaps
	@ ${INSTALL_DATA} \
		`find ${WRKSRC}/examples \! -type d | grep -v pixmaps` \
		${PREFIX}/share/examples/EZ
	@ ${INSTALL_DATA} ${WRKSRC}/examples/pixmaps/* \
			${PREFIX}/share/examples/EZ/pixmaps
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/EZ
	@ ${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/EZ
	@ cd ${WRKSRC}; tar cf - html ps | \
		(cd ${PREFIX}/share/doc/EZ; tar --unlink -xf - )
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	1
.else
VERSION=	1.3
.endif
