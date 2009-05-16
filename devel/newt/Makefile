# New ports collection makefile for:	newt
# Date created:		08 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	newt
PORTVERSION=	0.51.0
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		# ftp://ftp.redhat.com/pub/redhat/linux/rawhide/SRPMS/SRPMS/
MASTER_SITE_SUBDIR=	perky
PKGNAMESUFFIX=	${PYTHONSUFFIX}${TCLSUFFIX}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Not Erik's Windowing Toolkit:  console I/O handling library#'

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2 \
		popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SOVERSION=	51
TCL_VERSION?=	tcl8.3
TCL_NODOT=	${TCL_VERSION:S/.//}
MAKE_ENV+=	PCFLAGS="${CFLAGS}" TCLVERSION="${TCL_VERSION}"
PLIST_SUB+=	SOVERSION=${SOVERSION} \
		EXAMPLESDIR="${EXAMPLESDIR:S,${PREFIX}/,,}"

.if defined(WITH_PYTHON)
PYTHONSUFFIX=	-${PYTHON_PKGNAMEPREFIX:S/-//}
BUILD_DEPENDS+=	${PYDISTUTILS}
USE_PYTHON=	yes
MAKE_ENV+=	WITH_PYTHON=yes
PLIST_SUB+=	PYTHONOPT=""
.else
PLIST_SUB+=	PYTHONOPT="@comment "
.endif

.if defined(WITH_TCL)
TCLSUFFIX=	-${TCL_NODOT}
LIB_DEPENDS+=	${TCL_NODOT}:${PORTSDIR}/lang/${TCL_NODOT}

MAKE_JOBS_SAFE=  yes
MAKE_ENV+=	WITH_TCL=yes
PLIST_SUB+=	TCLOPT=""
.else
PLIST_SUB+=	TCLOPT="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's,^\(SONAME=\).*,\1${SOVERSION},g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,PyMem_DEL,PyObject_DEL,g' \
		${WRKSRC}/snackmodule.c

.if defined(WITH_PYTHON)
post-build:
	@${LN} -sf ${WRKSRC}/libnewt.so.${SOVERSION} ${WRKSRC}/libnewt.so
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${FILESDIR}/setup.py build

post-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${FILESDIR}/setup.py \
		install --prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/peanuts.py ${WRKSRC}/popcorn.py \
		${EXAMPLESDIR}
.endif
.endif

.include <bsd.port.post.mk>
