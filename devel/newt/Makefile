# New ports collection makefile for:	newt
# Date created:		08 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	newt
PORTVERSION=	0.50.39
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		# ftp://ftp.redhat.com/pub/redhat/linux/rawhide/SRPMS/SRPMS/
MASTER_SITE_SUBDIR=	perky
PKGNAMESUFFIX=	${PYTHONSUFFIX}${TCLSUFFIX}

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
VERSION=	50
TCL_VERSION?=	tcl8.3
TCL_NODOT=	${TCL_VERSION:S/.//}
MAKE_ENV+=	VERSION=${VERSION} CC=${CC} PCFLAGS="${CFLAGS}" TCLVERSION="${TCL_VERSION}"
PLIST_SUB+=	VERSION=${VERSION} EXAMPLESDIR="${EXAMPLESDIR:S,${PREFIX}/,,}"
CPIO?=		/usr/bin/cpio

.if !defined(WITHOUT_PYTHON)
PYTHONSUFFIX=	-${PYTHON_PKGNAMEPREFIX:S/-//}
BUILD_DEPENDS+=	${PYDISTUTILS}
USE_PYTHON=	yes
MAKE_ENV+=	WITH_PYTHON=yes
PLIST_SUB+=	PYTHONOPT=""
.else
PLIST_SUB+=	PYTHONOPT="@comment "
.endif

.if !defined(WITHOUT_TCL)
TCLSUFFIX=	-${TCL_NODOT}
LIB_DEPENDS+=	${TCL_NODOT}:${PORTSDIR}/lang/${TCL_NODOT}
MAKE_ENV+=	WITH_TCL=yes
PLIST_SUB+=	TCLOPT=""
.else
PLIST_SUB+=	TCLOPT="@comment "
.endif

.if !defined(WITHOUT_PYTHON)
post-build:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${FILESDIR}/setup.py build

post-install:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} ${FILESDIR}/setup.py install --prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/peanuts.py ${WRKSRC}/popcorn.py ${EXAMPLESDIR}
.endif
.endif

.include <bsd.port.mk>
