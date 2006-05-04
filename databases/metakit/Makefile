# New ports collection makefile for:	metakit
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

PORTNAME=	metakit
PORTVERSION=	2.4.9.3
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/older/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ embedded database engine, supports Python and Tcl

.if defined(METAKIT_WITH_TCL83)
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83
.endif
.if defined(METAKIT_WITH_TCL84)
LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84
BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../unix/configure
INSTALLS_SHLIB=	yes
MAKE_ARGS=	CXXFLAGS="-Dq4_INLINE ${CFLAGS} -fpermissive"
ONLY_FOR_ARCHS=	i386 alpha

.if defined(WITHOUT_PYTHON)
METAKIT_WITHOUT_PYTHON=yes
.endif

.if !defined(METAKIT_WITHOUT_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
CATEGORIES+=	python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if defined(METAKIT_WITH_TCL83)
CATEGORIES+=	tcl83
TCL_V=		8.3
TCL_SHORT_V=	83
.endif

.if defined(METAKIT_WITH_TCL84)
CATEGORIES+=	tcl84
TCL_V=		8.4
TCL_SHORT_V=	84
.endif

.if defined(METAKIT_WITH_TCL83) || defined(METAKIT_WITH_TCL84)
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/include/tcl${TCL_V}
CONFIGURE_ENV+=	V=${TCL_V} SHORT_V=${TCL_SHORT_V}
MAKE_ENV+=	V=${TCL_V} SHORT_V=${TCL_SHORT_V}
PLIST_SUB+=	TCL_V="${TCL_V}"
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

.include <bsd.port.pre.mk>

pre-patch:
	${REINPLACE_CMD} -e "s=doc/==" ${WRKSRC}/../Metakit.html
.if defined(METAKIT_WITH_TCL83) || defined(METAKIT_WITH_TCL84)
	${REINPLACE_CMD} \
		-e "s/= tclsh/=tclsh${TCL_V}/" -e "s/tcl8.4/tcl${TCL_V}/" \
		${WRKSRC}/../unix/Makefile.in
.endif
.if !defined(METAKIT_WITHOUT_PYTHON)
	${REINPLACE_CMD} -e "s=python2.[0-9]=${PYTHON_VERSION}=" \
		${WRKSRC}/../unix/Makefile.in ${WRKSRC}/../unix/configure
.endif

post-build:
	(cd ${WRKSRC} && cc -shared `make -V LIBTOOL_SHLIB_FLAGS -V SHLOBJS` \
		-lc  -Wl,-soname -Wl,libmk4.so -o .libs/libmk4.so )
	${SED} -e 's|nstalled=no|installed=yes|' \
		${WRKSRC}/libmk4.la > ${WRKSRC}/.libs/libmk4.lai
.if !defined(METAKIT_WITHOUT_PYTHON)
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
.endif

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/libmk4.so \
		${PREFIX}/lib/libmk4.so.0
	@${LN} -sf libmk4.so.0 ${PREFIX}/lib/libmk4.so
	@${MV}  ${PREFIX}/lib/libmk4.al ${PREFIX}/lib/libmk4.a
.if !defined(METAKIT_WITHOUT_PYTHON)
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/libmk4py.a ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/libmk4py.so ${PREFIX}/lib
.endif
.if defined(METAKIT_WITH_TCL83) || defined(METAKIT_WITH_TCL84)
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/libmk4tcl.a ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/libmk4tcl.so ${PREFIX}/lib
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/../doc --exclude "*CVS" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	${INSTALL_DATA} ${WRKSRC}/../Metakit.html ${WRKSRC}/../CHANGES \
		${WRKSRC}/../README ${WRKSRC}/../WHATSNEW ${DOCSDIR}/
.endif

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.if defined(METAKIT_WITH_TCL83) || defined(METAKIT_WITH_TCL84)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test-tcl)
.endif

.include <bsd.port.post.mk>
