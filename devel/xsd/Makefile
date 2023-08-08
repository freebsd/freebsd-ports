PORTNAME=	xsd
DISTVERSION=	4.1.0.a11
PORTREVISION=	1
DISTVERSIONSUFFIX=	+dep
CATEGORIES=	devel
MASTER_SITES=	https://codesynthesis.com/~boris/tmp/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	W3C XML Schema to C++ translator
WWW=		https://www.codesynthesis.com/projects/xsd/

LICENSE=		FLOSSE GPLv2
LICENSE_COMB=		dual
LICENSE_NAME_FLOSSE=	FLOSS Exception
LICENSE_FILE_FLOSSE=	${WRKSRC}/xsd/FLOSSE
LICENSE_PERMS_FLOSSE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/build-0.3/abspath.make:devel/build
# libxsd-frontend should come from a separate port as well, but at the moment
# its distribution as a separate tarball is so poor that it does not even have
# a `make install'.
LIB_DEPENDS=	libcutl.so:devel/libcutl \
		libxerces-c.so:textproc/xerces-c3

USES=		compiler:c++11-lang ghostscript:build gmake localbase:ldflags tar:bzip2
# devel/libcutl 1.10.0 does not work with C++17 which is the default since
# clang 16. This can be removed once that port starts working with C++17 and
# has its own USE_CXXSTD removed.
USE_CXXSTD=	c++11

MAKEFILE=	makefile
MAKE_ARGS=	EXTERNAL_LIBCUTL=y \
		install_prefix=${STAGEDIR}${PREFIX} \
		install_man_dir=${STAGEDIR}${MANPREFIX}/man \
		verbose=1
ALL_TARGET=	# no default target should be passed to gmake.

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
# Use devel/build instead of the port's bundled copy.
	${RM} -r ${WRKSRC}/build-0.3
	${LN} -s ${LOCALBASE}/include/build-0.3 ${WRKSRC}/build-0.3
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/libxsd-frontend/version \
		${WRKSRC}/libxsd-frontend/version.txt

post-install:
# Install examples into the right directory.
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${DOCSDIR}/examples

.include <bsd.port.mk>
