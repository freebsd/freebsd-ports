# $FreeBSD$

PORTNAME=	ngs
DISTVERSION=	2.10.1
CATEGORIES=	biology
PKGNAMESUFFIX=	-sdk

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tools and libraries for using data in the INSDC Sequence Read Archives

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to configure: unsupported architecture 'FreeBSD'
NOT_FOR_ARCHS=		powerpc64
NOT_FOR_ARCHS_REASON=	os-arch.prl needs to be taught about powerpc64

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ncbi
ALL_TARGET=	default
USE_LDCONFIG=	yes

CFLAGS+=	-I${WRKSRC}/ngs-sdk/ngs/unix/${ARCH}/

post-patch:
	@cd ${WRKSRC}/ngs-sdk/ngs/unix && ${LN} -s x86_64 amd64

do-install:
	cd ${WRKSRC}/ngs-sdk && ${COPYTREE_SHARE} ngs ${STAGEDIR}/${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/ngs-sdk/${ARCH}-portbld-*/ngs-sdk/FreeBSD/clang/${ARCH}/rel/lib/libngs-sdk.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/
	cd ${STAGEDIR}${PREFIX}/lib/ && \
		${LN} -s libngs-sdk.so.${DISTVERSION} libngs-sdk.so.${DISTVERSION:R:R} && \
		${LN} -s libngs-sdk.so.${DISTVERSION:R:R} libngs-sdk.so
.for l in libngs-c++.a libngs-adapt-c++.a
	${INSTALL_LIB} ${WRKSRC}/ngs-sdk/${ARCH}-portbld-*/ngs-sdk/FreeBSD/clang/${ARCH}/rel/lib/${l}.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/${l}
.endfor

.include <bsd.port.mk>
