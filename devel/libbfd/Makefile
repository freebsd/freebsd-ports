PORTNAME=	libbfd
PORTVERSION=	2.33.1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Universal BFD library from GNU binutils

BROKEN_aarch64=		Fails to configure: machine aarch64-portbld not recognized
BROKEN_armv6=		Fails to configure: BFD does not support target armv6-portbld-freebsd12.0
BROKEN_armv7=		Fails to configure: BFD does not support target armv7-portbld-freebsd12.0
BROKEN_mips64=		Fails to configure: BFD does not support target mips64-portbld-freebsd12.0
BROKEN_riscv64=		Fails to configure: machine riscv64-portbld not recognized

CONFLICTS=	mingw-binutils binutils

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/bfd

USES=		libtool tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-install-libbfd \
		--disable-nls \
		--enable-shared \
		--enable-targets=all \
		--disable-werror
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
INFO=		bfd

pre-configure:
# Configure and build pic version of libiberty
	(cd ${WRKSRC}/../libiberty && \
		${SETENV} CC="${CC}" CFLAGS="${CFLAGS}" CPP="${CPP}" \
			CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
			LIBS="${LIBS}" ${CONFIGURE_ENV} ./configure \
			${CONFIGURE_ARGS} --build=${CONFIGURE_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
			${MAKE_ARGS})

.include <bsd.port.mk>
