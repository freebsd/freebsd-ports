PORTNAME=	quilc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.26.0
PORTREVISION=	1
CATEGORIES=	lang # quantum-computing
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION} # many files, some are unversioned
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimizing Quil compiler (for quantum computing)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	sbcl:lang/sbcl \
		cppzmq>0:net/cppzmq
LIB_DEPENDS=	libblas.so:math/blas \
		libffi.so:devel/libffi \
		liblapack.so:math/lapack

USES=		fortran gmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	quil-lang

BINARY_ALIAS=	cc=${FILESDIR}/cc \
		gfortran=gfortran${GCC_DEFAULT} \
		git=false

PLIST_FILES=	bin/quilc \
		lib/libexpokit.so

#
# In order to update dependencies:
# 1. set MAINTAINER_MODE=yes
# 2. make clean build
# 3. set MAINTAINER_MODE=no
# 4. make clean makesum
#

MAINTAINER_MODE=	no

.if (${MAINTAINER_MODE} == "yes")
BUILD_DEPENDS+=	curl:ftp/curl

do-build:
	# build, download dependencies during build, and save build log with URLs in it
	@set -e; set -o pipefail; cd ${WRKSRC} && (${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${TARGET_ALL} 2>&1 | tee -a ${WRKDIR}/build.log)
	# compute Makefile.deps based on URLs in build.log
	@${FILESDIR}/build-log-to-makefile-deps ${WRKDIR}/build.log > Makefile.deps
.else
.  include <Makefile.deps>

MASTER_SITES=	${MASTER_SITES_DEPS}
DISTFILES=	${DISTFILES_DEPS}

QL_DIR=		${WRKDIR}/quicklisp

post-extract:
	# create directories
	@${MKDIR} \
		${QL_DIR} \
		${QL_DIR}/dists/quicklisp \
		${QL_DIR}/dists/quicklisp/software
	# copy files
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/asdf.lisp ${QL_DIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/setup.lisp ${QL_DIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/releases.txt ${QL_DIR}/dists/quicklisp
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/systems.txt ${QL_DIR}/dists/quicklisp
	# extract archives
	@cd ${QL_DIR} && ${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/quicklisp.tar
	# extract tarballs
.  for t in ${DISTFILES_DEPS:C/:.*//:M*.tgz}
	@cd ${QL_DIR}/dists/quicklisp/software && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/${t}
.  endfor
	# fixups: same effect as https://github.com/cffi/cffi/pull/332
	@${REINPLACE_CMD} -e 's|:openbsd "libffi.so"|:freebsd "libffi.so"|' ${QL_DIR}/dists/quicklisp/software/cffi_0.24.1/libffi/libffi.lisp

post-install:
	${INSTALL_LIB} ${QL_DIR}/dists/quicklisp/software/magicl-v0.9.1/expokit/libexpokit.so ${STAGEDIR}${PREFIX}/lib

.endif

.include <bsd.port.mk>
