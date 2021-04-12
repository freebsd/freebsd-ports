PORTNAME=	ngs
DISTVERSION=	2.11.0
PORTREVISION=	2
CATEGORIES=	biology
PKGNAMESUFFIX=	-sdk

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools and libraries for using data in the INSDC Sequence Read Archives

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to configure: unsupported architecture 'FreeBSD'
BROKEN_riscv64=		fails to configure: unsupported architecture 'FreeBSD'
NOT_FOR_ARCHS=		powerpc64
NOT_FOR_ARCHS_REASON=	os-arch.prl needs to be taught about powerpc64

USES=		compiler:c++11-lang gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${STAGEDIR}${PREFIX}" --build-prefix="${WRKSRC}/build"

ALL_TARGET=	ngs-sdk

post-extract:
	@cd ${WRKSRC}/ngs-sdk/ngs/unix && ${LN} -s x86_64 amd64

do-install: # install target from the project breaks: https://github.com/ncbi/ngs/issues/34
	# install headers
	cd ${WRKSRC}/ngs-sdk && ${COPYTREE_SHARE} ngs ${STAGEDIR}${PREFIX}/include
	${RM} -r ${STAGEDIR}${PREFIX}/include/ngs/win
	# install libraries
	cd ${WRKSRC}/build/ngs-sdk/FreeBSD/clang/amd64/rel/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
		# The above command installs broken-looking static libs with symlinks.
		# This is intentional, see comments https://github.com/ncbi/ncbi-vdb/issues/36#issuecomment-817990790 This may change in future versions.
	# strip
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libngs-sdk.so.2.11.0

.include <bsd.port.mk>
