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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ embedded database engine, supports Python and Tcl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../license.terms

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../unix/configure
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 alpha amd64

OPTIONS_DEFINE=	PYTHON TCL DOCS
OPTIONS_DEFAULT=	PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
CATEGORIES+=	python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
CATEGORIES+=	tcl
USE_TCL=	84+
.endif

.include <bsd.port.pre.mk>

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
.if ${PORT_OPTIONS:MPYTHON}
	${REINPLACE_CMD} -e "s=python2.[0-9]=${PYTHON_VERSION}=" \
		${WRKSRC}/../unix/Makefile.in ${WRKSRC}/../unix/configure
.endif

post-build:
.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
.endif

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libmk4.so \
		${PREFIX}/lib/libmk4.so.0
	@${LN} -sf libmk4.so.0 ${PREFIX}/lib/libmk4.so
.if ${PORT_OPTIONS:MDOCS}
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
