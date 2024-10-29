PORTNAME=	newlib
PORTVERSION=	4.4.0
DISTVERSIONSUFFIX=	.20231231
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}
PKGNAMEPREFIX=	${NEWLIB_TARGET}-

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Newlib distribution for ${NEWLIB_TARGET} targets
WWW=		https://www.sourceware.org/newlib/

BUILD_DEPENDS+=	${NEWLIB_TARGET}-ar:devel/binutils@${NEWLIB_TARGET:C/-/_/g} \
		${NEWLIB_TARGET}-as:devel/binutils@${NEWLIB_TARGET:C/-/_/g} \
		${NEWLIB_TARGET}-ld:devel/binutils@${NEWLIB_TARGET:C/-/_/g} \
		${LOCALBASE}/bin/${NEWLIB_TARGET}-gcc:devel/${NEWLIB_TARGET}-gcc

NEWLIB_TARGET?=	arm-none-eabi

USES=		cpe gmake makeinfo
CPE_VENDOR=	${PORTNAME}_project
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
		--target="${NEWLIB_TARGET}" \
		--disable-newlib-supplied-syscalls \
		--enable-multilib \
		--enable-newlib-nano-malloc \
		--enable-newlib-nano-formatted-io \
		--enable-target-optspace

INSTALL_TARGET=	install-target

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/info
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${NEWLIB_TARGET} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
