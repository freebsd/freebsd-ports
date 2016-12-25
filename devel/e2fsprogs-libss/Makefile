# Created by: Ben Kaduk <kaduk@mit.edu>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel
PKGNAMESUFFIX=	-libss

MAINTAINER=	kaduk-fbsd@mit.edu
COMMENT=	Command-line interface parsing library from e2fsprogs

CONFLICTS=	heimdal-[0-9]*
CONFLICTS+=	krb4-[0-9]*

BROKEN_mips=		Does not build: expected declaration specifiers before size_t
BROKEN_mips64=		Does not build: expected declaration specifiers before size_t
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build: expected declaration specifiers before size_t

OPTIONS_EXCLUDE=	DOCS EXAMPLES IPV6 NLS
CONFIGURE_ARGS=	--enable-elf-shlibs
MASTERDIR=	${.CURDIR}/../../sysutils/e2fsprogs
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/lib/ss
INSTALL_WRKSRC=	${WRKSRC}/lib/ss
FILESDIR=	${.CURDIR}/files

PKGDIR=		${.CURDIR}

pre-build:
	@(cd ${WRKSRC}/lib/ss && compile_et ss_err.et && \
	${REINPLACE_CMD} -f ${FILESDIR}/fix-ss_err.h.sed ss_err.h)

.include "${MASTERDIR}/Makefile"
