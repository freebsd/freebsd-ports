PORTNAME=	newlib
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/${PORTNAME}/ \
		SOURCEWARE/${PORTNAME}
PKGNAMEPREFIX=	${NEWLIB_TARGET}-

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Newlib distribution for ${NEWLIB_TARGET} targets

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
		--enable-multilib

# Disable installation of .info files and fix includedir reference.
post-patch:
	@${REINPLACE_CMD} -E 's/^(install.*:.*)install-info(.*)/\1\2/' ${WRKSRC}/etc/Makefile.in

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${PREFIX}/${NEWLIB_TARGET} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
