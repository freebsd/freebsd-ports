# New ports collection makefile for:	libcii
# Version required:	1.1
# Date created:		21 April 1998
# Whom:			J Han <hjh@photino.com>
#
# $Id$
#

DISTNAME=	cii11
PKGNAME=	libcii-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.princeton.edu/pub/packages/cii/

MAINTAINER=	hjh@photino.com

NO_INSTALL_MANPAGES=	yes
NO_WRKSUBDIR=	yes

SAMPLES=	double calc ids	mpcalc wf xref cref iref kref \
		idents words basename dirname sort spin	sieve

CIIBUILD=	${WRKDIR}/${PKGNAME}
CIICUSTOM=	${FILESDIR}/freebsd.mk
CIIMAJOR=	1
CIIDEST=	${PREFIX}/lib/cii

MAKEFILE=	makefile
MAKE_FLAGS+=	BUILDDIR=${PKGNAME}	#	${CIIBUILD}
MAKE_FLAGS+=	CUSTOM=${CIICUSTOM}

pre-build:
	@${MKDIR} ${CIIBUILD}
	@${MKDIR} ${CIIBUILD}/include
	@${CP} ${WRKDIR}/include/*.h ${CIIBUILD}/include

do-build:
	@(cd ${WRKDIR}; ${MAKE} ${MAKE_FLAGS})

# /usr/local/lib/cii/1/
# /usr/local/lib/cii/1/include
#
# libcii.a is placed in /usr/local/lib
# .h is placed in	/usr/local/include/cii
#
do-install:
	@${MKDIR} ${CIIDEST}
	@${MKDIR} ${CIIDEST}/${CIIMAJOR}
	@${MKDIR} ${CIIDEST}/${CIIMAJOR}/include
	@${MKDIR} ${CIIDEST}/${CIIMAJOR}/examples
#	@${MKDIR} ${PREFIX}/include/cii
##
	${INSTALL} ${COPY} ${CIIBUILD}/libcii.a ${CIIDEST}/${CIIMAJOR}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${CIIDEST}/${CIIMAJOR}/include
##
	${LN} -s ${CIIDEST}/${CIIMAJOR}/libcii.a ${PREFIX}/lib/libcii.a
	${LN} -s ${CIIDEST}/${CIIMAJOR}/include ${PREFIX}/include/cii
##
	(for a in ${SAMPLES}; \
	do \
	${INSTALL_PROGRAM} ${CIIBUILD}/$$a ${CIIDEST}/${CIIMAJOR}/examples; \
	done)
##

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cii
	@${MKDIR} ${PREFIX}/share/doc/cii/examples
	@${MKDIR} ${PREFIX}/share/doc/cii/src
	${INSTALL_DATA} ${WRKSRC}/makefile ${PREFIX}/share/doc/cii
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cii
	${INSTALL_DATA} ${WRKSRC}/history.html ${PREFIX}/share/doc/cii
	${INSTALL_DATA} ${WRKSRC}/CPYRIGHT ${PREFIX}/share/doc/cii
	${INSTALL_DATA} ${WRKSRC}/install.html ${PREFIX}/share/doc/cii
	${INSTALL_DATA} ${WRKSRC}/packing.lst ${PREFIX}/share/doc/cii
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${PREFIX}/share/doc/cii/examples
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${PREFIX}/share/doc/cii/src
.endif

.include <bsd.port.mk>
