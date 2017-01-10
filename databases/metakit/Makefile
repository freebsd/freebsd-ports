# Created by: Russell L. Carter <rcarter@pinyon.org>
# $FreeBSD$

PORTNAME=	metakit
PORTVERSION=	2.4.9.7
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ embedded database engine with Python and Tcl support

LICENSE=	MIT

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../unix/configure
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/builds

BROKEN_aarch64=		Fails to build: error: typedef redefinition with different types
BROKEN_mips64=		Fails to build: error: conflicting declaration typedef long int t4_i32

OPTIONS_DEFINE=	PYTHON TCL DOCS
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
CATEGORIES+=	python
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl:85
CATEGORIES+=	tcl
CONFIGURE_ARGS+=--with-tcl=${TCL_INCLUDEDIR}
CONFIGURE_ENV+=	TCL_LIBDIR=${TCL_LIBDIR}
PLIST_SUB+=	TCL_V="${TCL_VER}"
.endif

pre-patch:
	@${REINPLACE_CMD} -e "s=doc/==" ${WRKSRC}/../Metakit.html
	@${REINPLACE_CMD} -e "s|= tclsh|=${TCLSH}|" \
		${WRKSRC}/../unix/Makefile.in
	@${REINPLACE_CMD} -e "s=python2.[0-9]=${PYTHON_VERSION}=" \
		${WRKSRC}/../unix/Makefile.in ${WRKSRC}/../unix/configure

post-build-PYTHON-on:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python

pre-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmk4.so \
		${STAGEDIR}${PREFIX}/lib/libmk4.so.0
	${LN} -sf libmk4.so.0 ${STAGEDIR}${PREFIX}/lib/libmk4.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/../doc --exclude "*CVS" -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -
	${INSTALL_DATA} ${WRKSRC}/../Metakit.html ${WRKSRC}/../CHANGES \
		${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

do-test-TCL-on:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test-tcl)

.include <bsd.port.mk>
