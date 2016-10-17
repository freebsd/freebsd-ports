# $FreeBSD$

PORTNAME=	newlib
PORTVERSION=	2.4.0
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/${PORTNAME}/ \
		SOURCEWARE/${PORTNAME}
PKGNAMEPREFIX=	${NEWLIB_TARGET}-

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Newlib distribution for ${NEWLIB_TARGET} targets

BUILD_DEPENDS+=	${NEWLIB_TARGET}-ar:devel/${NEWLIB_TARGET}-binutils \
		${NEWLIB_TARGET}-as:devel/${NEWLIB_TARGET}-binutils \
		${NEWLIB_TARGET}-ld:devel/${NEWLIB_TARGET}-binutils \
		${LOCALBASE}/bin/${NEWLIB_TARGET}-gcc:devel/${NEWLIB_TARGET}-gcc

NEWLIB_TARGET?=	arm-none-eabi

USES=		gmake makeinfo
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --target="${NEWLIB_TARGET}" --disable-newlib-supplied-syscalls

# Disable installation of .info files and fix includedir reference.
post-patch:
	@${REINPLACE_CMD} -E 's/^(install.*:.*)install-info(.*)/\1\2/' ${WRKSRC}/etc/Makefile.in

.include <bsd.port.mk>
