# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libbfd
PORTVERSION=	2.19.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Universal BFD library from GNU binutils

CONFLICTS=	mingw-binutils-[0-9]* binutils-[0-9]*

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/bfd

USES=		gmake libtool tar:bzip2
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
