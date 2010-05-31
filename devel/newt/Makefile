# New ports collection makefile for:	newt
# Date created:		08 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	newt
PORTVERSION=	0.52.11
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/n/e/newt/
PKGNAMESUFFIX=	${PYTHONSUFFIX}${TCLSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Not Erik's Windowing Toolkit:  console I/O handling library#'

LIB_DEPENDS=	slang:${PORTSDIR}/devel/libslang2 \
		popt:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SOVERSION=	${PORTVERSION:R:E}
TCL_NODOT=	tcl${TCL_VER:S/.//}
CFLAGS+=	-Werror
MAKE_ENV+=	PCFLAGS="${CFLAGS}" TCLVERSION="tcl${TCL_VER}"
PLIST_SUB+=	SOVERSION=${SOVERSION} \
		VERSION=${PORTVERSION}	\
		EXAMPLESDIR="${EXAMPLESDIR:S,${PREFIX}/,,}"
SUB_LIST=	VERSION=${PORTVERSION}

USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
.endif
.if defined(WITH_PYTHON)
PYTHONSUFFIX=	-${PYTHON_PKGNAMEPREFIX:S/-//}
BUILD_DEPENDS+=	${PYDISTUTILS}
USE_PYTHON=	yes
MAKE_ENV+=	WITH_PYTHON=yes
PLIST_SUB+=	PYTHONOPT=""	\
		PYNUM=${PYTHON_VERSION:S/python//}
SUB_FILES+=	setup.py
.else
PLIST_SUB+=	PYTHONOPT="@comment "
.endif

.if defined(WITH_TCL)
USE_TCL=	84+
TCLSUFFIX=	-${TCL_NODOT}
MAKE_ENV+=	WITH_TCL=yes TCL_LIBDIR=${TCL_LIBDIR:Q}
PLIST_SUB+=	TCLOPT="" TCL_VER=${TCL_VER}${_TCL_THREADS_SUFFIX}
CONFIGURE_ENV+=	CPPFLAGS=-I${TCL_INCLUDEDIR:Q}
SUB_FILES+=	pkgIndex.tcl

pre-su-install:
	${MKDIR} ${TCL_LIBDIR}/whip

.else
PLIST_SUB+=	TCLOPT="@comment "
CONFIGURE_ARGS+=--without-tcl
.endif

MAN1=	whiptail.1

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,^\(SONAME=\).*,\1${SOVERSION},g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/include/slang|${LOCALBASE:Q}/include|' \
		-e 's|-lslang|-lcurses -L${LOCALBASE:Q}/lib -lslang|'	\
		-e 's|-ltcl8.4||'	\
		-e 's|^pkgconfigdir.*|pkgconfigdir=${LOCALBASE:Q}/libdata/pkgconfig|'	\
		-e 's,PYTHONVERS =.*,PYTHONVERS=${PYTHON_VER},' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's,PyMem_DEL,PyObject_DEL,g' \
		${WRKSRC}/snackmodule.c

.if defined(WITH_PYTHON)
pre-install:
	@${LN} -sf ${WRKSRC}/libnewt.so.${SOVERSION} ${WRKSRC}/libnewt.so
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${WRKDIR}/setup.py build
.endif

post-install:
.if defined(WITH_TCL)
	${INSTALL_DATA} ${WRKDIR}/pkgIndex.tcl ${TCL_LIBDIR}/whip/
.endif
.if defined(WITH_PYTHON)
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${WRKDIR}/setup.py install --prefix=${PREFIX}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/peanuts.py ${WRKSRC}/popcorn.py ${EXAMPLESDIR}/
.endif
.endif

.include <bsd.port.post.mk>
