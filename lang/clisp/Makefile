# New ports collection makefile for:    clisp
# Date created:         Feb  5 2000
# Whom:                 Jeff Brown <jabrown@caida.org>
#
# $FreeBSD$
#

PORTNAME=	clisp
PORTVERSION=	2.33.2
PORTREVISION=	1
CATEGORIES=	lang lisp
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=${PORTNAME}/release/${PORTVERSION}

MAINTAINER=	jakub@rehor.net
COMMENT=	An ANSI Common Lisp

USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes

# Build subdirectory
BUILD_DIRNAME=${CONFIGURE_TARGET}

# Check ./configure --help in the distribution to see all modules
MAKEMAKE_ARGS=--prefix=${PREFIX} --with-readline --with-gettext \
	--with-dynamic-ffi --with-module=regexp --with-export-syscalls

.include <bsd.port.pre.mk>

# Does not compile on 64-bit architectures
# See http://sourceforge.net/mailarchive/message.php?msg_id=7103089
# for discussion.
.if ${ARCH} == "alpha" || ${ARCH} == "ia64" || ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		"Does not compile on 64-bit architectures"
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
