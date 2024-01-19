PORTNAME=	xsd
DISTVERSION=	4.2.0
CATEGORIES=	devel
MASTER_SITES=	https://www.codesynthesis.com/download/${PORTNAME}/${DISTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	W3C XML Schema to C++ translator
WWW=		https://www.codesynthesis.com/projects/xsd/

LICENSE=		FLOSSE GPLv2
LICENSE_COMB=		dual
LICENSE_NAME_FLOSSE=	FLOSS Exception
LICENSE_FILE_FLOSSE=	${WRKSRC}/FLOSSE
LICENSE_PERMS_FLOSSE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	build2>=0:devel/build2
LIB_DEPENDS=	libcutl.so:devel/libcutl \
		libxerces-c.so:textproc/xerces-c3 \
		libxsd-frontend.so:devel/libxsd-frontend

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

post-install:
# Rename the xsd binary to xsdcxx, as lang/mono already installs an executable
# called `xsd'.
	@cd ${STAGEDIR}${PREFIX}/bin && ${MV} xsd xsdcxx
	@cd ${STAGEDIR}${PREFIX}/share/man/man1 && ${MV} xsd.1 xsdcxx.1

.include <bsd.port.mk>
