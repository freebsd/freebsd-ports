# New ports collection makefile for:	newt
# Date created:		08 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	newt
PORTVERSION=	${RPMVERSION}.${RPMREVISION}
CATEGORIES=	devel
MASTER_SITES=	http://www.silug.org/%SUBDIR%/ \
		ftp://ftp.redhat.com/%SUBDIR%/ \
		http://ftp.dulug.duke.edu/%SUBDIR%/ 
MASTER_SITE_SUBDIR=	pub/redhat/linux/rawhide/SRPMS/SRPMS
DISTNAME=	${PORTNAME}-${RPMVERSION}-${RPMREVISION}
EXTRACT_SUFX=	.src.rpm
PKGNAMESUFFIX=	${PYTHONSUFFIX}${TCLSUFFIX}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		popt.0:${PORTSDIR}/devel/popt

RPMVERSION=	0.50.36
RPMREVISION=	1
WRKSRC=		${WRKDIR}/newt-${RPMVERSION}

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
VERSION=	0.50
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

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${LOCALBASE}/bin/rpm2cpio ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR};${CPIO} -i)
	@${TAR} xfz ${WRKSRC}.tar.gz -C ${WRKDIR}

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
