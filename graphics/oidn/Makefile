# $FreeBSD$

PORTNAME=	oidn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://freebsd.org/:weights # bogus URL to make the framework happy, the fetch uses Git URL below
DISTFILES=	${PORTNAME}-weights-${WEIGHTS_GIT_HASH}${EXTRACT_SUFX}:weights

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel(R) Open Image Denoise library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Intel(R) MKL-DNN supports x86 64 bit platforms only (oidn contains a custom version of mkl-dnn, see math/mkl-dnn), and ISPC has a limited availability

FETCH_DEPENDS=	git:devel/git \
		git-lfs:devel/git-lfs
BUILD_DEPENDS=	ispc>=1.14.1:devel/ispc
LIB_DEPENDS=	libtbb.so:devel/tbb

USES=		cmake:noninja compiler:c++11-lang python:build
USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageDenoise
GH_TUPLE=	\
		OpenImageDenoise:mkl-dnn:603620ba45185e7d91fe112b69287e7d86c64353:m/mkl-dnn
#		OpenImageDenoise:oidn-weights:08092e46a1961b13b70e48ad80fa19b452bd4c01:w/weights # replaced with git clone in post-fetch because it needs git-lfs

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

CMAKE_ARGS+=	-DTBB_ROOT:STRING=${LOCALBASE} -DTBB_INCLUDE_DIR:STRING=${LOCALBASE}/include -DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD}

DOCSDIR=	share/doc/${GH_ACCOUNT}

WEIGHTS_GIT_URL=	https://github.com/OpenImageDenoise/oidn-weights.git
WEIGHTS_GIT_HASH=	08092e46a1961b13b70e48ad80fa19b452bd4c01

pre-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-weights-${WEIGHTS_GIT_HASH}${EXTRACT_SUFX}" ]; then \
		${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
		cd ${DISTDIR}/${DIST_SUBDIR} && \
		${ECHO} "==> Fetching the oidn/weights subproject with large LFS files" && \
		( \
			${MKDIR} ${WRKDIR}; \
			HOME=${WRKDIR}; \
			git config --global filter.lfs.smudge "git-lfs smudge -- %f" && \
			git clone -q ${WEIGHTS_GIT_URL} ${PORTNAME}-weights-${WEIGHTS_GIT_HASH} && \
			(cd ${PORTNAME}-weights-${WEIGHTS_GIT_HASH} && git reset -q --hard ${WEIGHTS_GIT_HASH} && ${RM} -r .git) && \
			${RM} -r ${WRKDIR} \
		) && \
		${FIND} ${PORTNAME}-weights-${WEIGHTS_GIT_HASH} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		${FIND} ${PORTNAME}-weights-${WEIGHTS_GIT_HASH} -print0 | LC_ALL=C ${SORT} -z | \
		${TAR} czf ${PORTNAME}-weights-${WEIGHTS_GIT_HASH}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
		${RM} -r ${PORTNAME}-weights-${WEIGHTS_GIT_HASH}; \
	fi

post-extract:
	@cd ${WRKSRC} && ${RMDIR} weights && ${LN} -s ${WRKDIR}/${PORTNAME}-weights-${WEIGHTS_GIT_HASH} weights

.include <bsd.port.mk>
