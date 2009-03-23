# New ports collection makefile for:	metakit
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

PORTNAME=	metakit
PORTVERSION=	2.4.9.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	C++ embedded database engine, supports Python and Tcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/builds
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_SCRIPT=	../unix/configure
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 alpha amd64

OPTIONS=	PYTHON	"Enable Python support"	on \
		TCL	"Enable Tcl support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
CATEGORIES+=	python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if defined(WITH_TCL) 
CATEGORIES+=	tcl
USE_TCL=	83+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
.endif

.if defined(USE_TCL)
CONFIGURE_ARGS+=	--with-tcl=${TCL_INCLUDEDIR}
CONFIGURE_ENV+=		TCL_LIBDIR=${TCL_LIBDIR}
PLIST_SUB+=	TCL_V="${TCL_VER}"
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

pre-patch:
	${REINPLACE_CMD} -e "s=doc/==" ${WRKSRC}/../Metakit.html
.if defined(USE_TCL)
	${REINPLACE_CMD} -e "s/= tclsh/=tclsh${TCL_VER}/" \
		${WRKSRC}/../unix/Makefile.in
.endif
.if !defined(WITHOUT_PYTHON)
	${REINPLACE_CMD} -e "s=python2.[0-9]=${PYTHON_VERSION}=" \
		${WRKSRC}/../unix/Makefile.in ${WRKSRC}/../unix/configure
.endif

post-build:
.if !defined(WITHOUT_PYTHON)
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
.endif

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libmk4.so \
		${PREFIX}/lib/libmk4.so.0
	@${LN} -sf libmk4.so.0 ${PREFIX}/lib/libmk4.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/../doc --exclude "*CVS" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	${INSTALL_DATA} ${WRKSRC}/../Metakit.html ${WRKSRC}/../CHANGES \
		${WRKSRC}/../README ${DOCSDIR}/
.endif

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.if defined(USE_TCL)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test-tcl)
.endif

.include <bsd.port.post.mk>
