PORTNAME=	libcii
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.princeton.edu/pub/packages/cii/
DISTNAME=	cii11

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library from "C Interfaces and Implementations" by David Hanson

NO_WRKSUBDIR=	yes

MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DMAXALIGN=8 -Iinclude" \
		AS="${CC} -c -x assembler-with-cpp -traditional" \
		LD="${CC}" LDFLAGS="" EXTRAS="" BUILDDIR=${PKGNAME}
PLIST_SUB=	CIIMAJOR="${CIIMAJOR}"

CIIBUILD=	${WRKSRC}/${PKGNAME}
CIIMAJOR=	1
CIIDEST=	${PREFIX}/lib/cii

SAMPLES=	double calc ids	mpcalc wf xref cref iref kref \
		idents words basename dirname
I386_SAMPLES=	sort spin sieve

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
MAKE_ARGS+=	"THREADS="
PLIST_SUB+=	NOTI386="@comment "
.else
PLIST_SUB+=	NOTI386=""
.endif

post-patch:
.if ${ARCH} != "i386"
.  for i in ${I386_SAMPLES}
	@${REINPLACE_CMD} -e 's/^	*\$$B${i}\$$E *\\\{0,1\}//' \
	                  ${WRKSRC}/makefile
.  endfor
.endif

pre-build:
	@${MKDIR} ${CIIBUILD}
	@${MKDIR} ${CIIBUILD}/include
	@${CP} ${WRKSRC}/include/*.h ${CIIBUILD}/include

# ${PREFIX}/lib/cii/${CIIMAJOR}/
# ${PREFIX}/lib/cii/${CIIMAJOR}/include
#
# libcii.a is placed in ${PREFIX}/lib
# .h is placed in	${PREFIX}/include/cii
#
do-install:
	@${MKDIR} ${STAGEDIR}${CIIDEST}
	@${MKDIR} ${STAGEDIR}${CIIDEST}/${CIIMAJOR}
	@${MKDIR} ${STAGEDIR}${CIIDEST}/${CIIMAJOR}/include
	@${MKDIR} ${STAGEDIR}${CIIDEST}/${CIIMAJOR}/examples
##
	${INSTALL_DATA} ${CIIBUILD}/libcii.a ${STAGEDIR}${CIIDEST}/${CIIMAJOR}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${CIIDEST}/${CIIMAJOR}/include
##
	${LN} -sf ${CIIDEST}/${CIIMAJOR}/libcii.a ${STAGEDIR}${PREFIX}/lib/libcii.a
	${LN} -sf ${CIIDEST}/${CIIMAJOR}/include ${STAGEDIR}${PREFIX}/include/cii
##
.for a in ${SAMPLES}
	${INSTALL_PROGRAM} ${CIIBUILD}/${a} ${STAGEDIR}${CIIDEST}/${CIIMAJOR}/examples
.endfor
.if ${ARCH} == "i386"
.  for a in ${I386_SAMPLES}
	${INSTALL_PROGRAM} ${CIIBUILD}/${a} ${STAGEDIR}${CIIDEST}/${CIIMAJOR}/examples
.  endfor
.endif
##
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cii
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cii/examples
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cii/src
.for f in CPYRIGHT README history.html install.html makefile packing.lst
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/share/doc/cii
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${PREFIX}/share/doc/cii/examples
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/share/doc/cii/src

.include <bsd.port.post.mk>
