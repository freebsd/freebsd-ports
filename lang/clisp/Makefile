# New ports collection makefile for:    clisp
# Date created:         Feb  5 2000
# Whom:                 Jeff Brown <jabrown@caida.org>
#
# $FreeBSD$
#

PORTNAME=	clisp
PORTVERSION=	2000.03.06
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp2.cons.org/pub/lisp/clisp/source/ \
		ftp://ftp.freesoftware.com/pub/lisp/clisp/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	jabrown@caida.org

USE_BZIP2=	yes

# Build subdirectory
BUILD_DIRNAME=obj

# These came from clisp's "configure" on my system.
MAKEMAKE_ARGS=--prefix=${PREFIX} --with-readline --with-gettext \
	--with-dynamic-ffi

# The post-install target uses these to fix permissions.
DATA_PATHS=${PREFIX}/lib/clisp ${PREFIX}/share/doc/clisp \
	${PREFIX}/share/locale/de/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/en/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/es/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/fr/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/nl/LC_MESSAGES/clisp.mo
PROG_PATHS=${PREFIX}/bin/clisp
MAN_PATHS=${PREFIX}/man/man1/clisp.1 ${PREFIX}/man/man3/clreadline.3

# The source doesn't include a top-level Makefile, so we'll fake one.
post-extract:
	@cd ${WRKSRC} && \
	printf "all install:\n\t@cd ${WRKSRC}/${BUILD_DIRNAME} && \$${MAKE} \$${MAKEFLAGS} \$$@\n" > ${WRKSRC}/Makefile

# It looks like the 'configure' script in the source gets seriously confused
# by the environment it gets from GNU_CONFIGURE=YES, so we'll call it here.
#
# The 'configure' wants the CC environment variable to include CFLAGS; but
# I'll edit it since if CFLAGS includes "-pipe", configure gets stuck reading
# from stdin, using the assembler in gcc 2.7.2.3
pre-configure:
	@cd ${WRKSRC} && \
	${RM} -rf ${BUILD_DIRNAME} && \
	${SETENV} CC="${CC} `echo ${CFLAGS} | ${SED} s/-pipe//`" \
		./configure --prefix=${PREFIX} ${BUILD_DIRNAME}

# The 'configure' script stops short of doing this for us.
post-configure:
	@cd ${WRKSRC}/${BUILD_DIRNAME} && \
	./makemake ${MAKEMAKE_ARGS} > Makefile && \
	make config.lsp

# The build uses INSTALL_* to copy files around, but since the Ports
# INSTALL_* try to set file permissions, using them breaks non-root builds.
# Instead, we'll just fix up permissions after we install the files.
post-install:
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PROG_PATHS}
	${CHMOD} -R ugo+rX,ugo-w ${PROG_PATHS}
	${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${DATA_PATHS}
	${CHMOD} -R ugo+rX,ugo-w ${DATA_PATHS}
	${CHOWN} -R ${MANOWN}.${MANGRP} ${MAN_PATHS}
	${CHMOD} -R ugo+rX,ugo-w ${MAN_PATHS}

MAN1=	clisp.1
MAN3=	clreadline.3

.include <bsd.port.mk>
