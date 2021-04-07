PORTNAME=	pbbam
DISTVERSION=	0.18.0 # Test with biology/unanimity before upgrading!
PORTREVISION=	5
CATEGORIES=	biology

# As of March 2018, unanimity is no longer open source.
# See https://github.com/PacificBiosciences/ccs.
MAINTAINER=     ports@FreeBSD.org
COMMENT=	PacBio BAM C++ library, with SWIG bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhts.so:biology/htslib \
		libboost_regex.so:devel/boost-libs

# Meson needs BOOST_ROOT=${LOCALBASE}
# https://github.com/mesonbuild/meson/issues/2239
USES=		compiler:c++14-lang localbase meson pkgconfig python
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	PacificBiosciences

pre-configure:
	@${REINPLACE_CMD} -e "s|'python'|'${PYTHON_VERSION}'|g" \
		${WRKSRC}/meson.build

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbbam.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbbam.so.0.18
	${RLN} ${STAGEDIR}${PREFIX}/lib/libpbbam.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/libpbbam.so.0

.include <bsd.port.mk>
