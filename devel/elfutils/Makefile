# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elfutils
PORTVERSION=	0.174
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://sourceware.org/elfutils/ftp/${PORTVERSION}/

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Library for manipulating ELF files and partial implementation of binutils

LICENSE=	LGPL3 GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING-GPLV2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING-LGPLV3

BROKEN_armv6=		fails to build: fails to compile i386_disasm.c
BROKEN_armv7=		fails to build: fails to compile i386_disasm.c
BROKEN_sparc64=		sparc patch does not apply cleanly to 0.172

LIB_DEPENDS=	libargp.so:devel/argp-standalone
PATCH_DEPENDS=	${NONEXISTENT}:devel/gnulib:extract

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext  # used anyway
NLS_CONFIGURE_ENABLE=	nls

USES=		autoreconf gmake libtool tar:bzip2
USE_GCC=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-null-dereference -Wno-unused-value
# For GCC8:
CFLAGS+=	-Wno-cast-function-type
# Give i386 a prayer of building, and we can fix the warnings later:
CFLAGS_i386+=	-Wno-error

# Avoid conflict with binutils / elftoolchain programs with the same names:
CONFIGURE_ARGS+=	--program-prefix=eu-

post-patch:
	@${LN} -s `${MAKE} -C ${PORTSDIR}/devel/gnulib -V WRKSRC` ${WRKDIR}/gnulib
	@${CP} -a \
	    ${WRKDIR}/gnulib/lib/obstack.c \
	    ${WRKDIR}/gnulib/lib/obstack.h \
	    ${WRKDIR}/gnulib/lib/obstack_printf.c \
	    ${WRKSRC}/lib

.include <bsd.port.mk>
