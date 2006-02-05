# New ports collection makefile for:    clisp
# Date created:         Feb  5 2000
# Whom:                 Jeff Brown <jabrown@caida.org>
#
# $FreeBSD$
#

PORTNAME=	clisp
PORTVERSION=	2.38
CATEGORIES=	lang lisp
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=${PORTNAME}/release/${PORTVERSION}

MAINTAINER=	jakub@rehor.net
COMMENT=	A Common Lisp implementation

BUILD_DEPENDS=	${LOCALBASE}/lib/libsigsegv.a:${PORTSDIR}/devel/libsigsegv \
		dvipdf:${PORTSDIR}/${GHOSTSCRIPT_PORT}

USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes

# Build subdirectory
BUILD_DIRNAME=${CONFIGURE_TARGET}

# Check ./configure --list-modules in the distribution to see all modules
MAKEMAKE_ARGS=--prefix=${PREFIX} --mandir=${PREFIX}/man --with-dynamic-ffi \
	--with-module=rawsock --with-module=wildcard --srcdir=${WRKSRC}/src

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == ia64
CONFIGURE_ARGS= --disable-mmap ${CONFIGURE_ARGS}
.endif

# The source doesn't include a top-level Makefile, so we'll fake one.
post-extract:
	@cd ${WRKSRC} && \
	${PRINTF} "all install:\n\t@cd ${WRKSRC}/${BUILD_DIRNAME} && \$${MAKE} \$${MAKEFLAGS} \$$@\n" > ${WRKSRC}/Makefile

# The 'configure' script stops short of doing this for us.
post-configure:
	cd ${WRKSRC}/${BUILD_DIRNAME} && \
	./makemake ${MAKEMAKE_ARGS} > Makefile && \
	make config.lisp

MAN1=	clisp.1

.include <bsd.port.post.mk>
