PORTNAME=	libxsd-frontend
DISTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	https://www.codesynthesis.com/download/xsd/4.2/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	W3C XML Schema compiler frontend
WWW=		https://www.codesynthesis.com/projects/libxsd-frontend/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPLv2

BUILD_DEPENDS=	build2>=0.16.0:devel/build2
LIB_DEPENDS=	libcutl.so:devel/libcutl \
		libxerces-c.so:textproc/xerces-c3

USES=		compiler:c++2b-lang pkgconfig

OPTIONS_DEFINE=	DOCS

B_CMD=		${LOCALBASE}/bin/b
B_ARGS=		-V -j ${MAKE_JOBS_NUMBER} -J ${MAKE_JOBS_NUMBER}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${B_CMD} configure ${B_ARGS} \
		config.cxx=${CXX} \
		config.cxx.coptions="${CXXFLAGS}" \
		config.cxx.loptions="${LDFLAGS} ${STRIP}" \
		config.bin.lib=shared \
		config.bin.rpath=${PREFIX}/lib \
		config.install.chroot=${STAGEDIR} \
		config.install.root=${PREFIX}
do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${B_CMD} install ${B_ARGS}

.include <bsd.port.mk>
