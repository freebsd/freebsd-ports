# New ports collection makefile for:    clisp
# Date created:         Feb  5 2000
# Whom:                 Jeff Brown <jabrown@caida.org>
#
# $FreeBSD$
#

PORTNAME=	clisp
PORTVERSION=	2.27
CATEGORIES=	lang
MASTER_SITES=	ftp://clisp.cons.org/pub/clisp/${PORTVERSION}/ \
		ftp://clisp.sourceforge.net/pub/clisp/${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jabrown@caida.org

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

# The build uses INSTALL_* to copy files around, but since the Ports
# INSTALL_* try to set file permissions, using them breaks non-root builds.
# Instead, we'll just fix up permissions in the post-install target, after we
# install the files.
CONFIGURE_ENV+=	INSTALL=${CP} INSTALL_DATA=${CP} INSTALL_PROGRAM=${CP} \
	INSTALL_SCRIPT=${CP} INSTALL_MAN=${CP}

# Build subdirectory
BUILD_DIRNAME=${CONFIGURE_TARGET}

# These came from clisp-2.27's "configure" on my 4.1.1-R system.
MAKEMAKE_ARGS=--prefix=${PREFIX} --with-readline --with-gettext \
	--with-dynamic-ffi --with-module=regexp --with-export-syscalls

# The post-install target uses these to fix permissions.
DATA_PATHS=${PREFIX}/lib/clisp ${PREFIX}/share/doc/clisp \
	${PREFIX}/share/locale/de/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/de/LC_MESSAGES/clisplow.mo \
	${PREFIX}/share/locale/en/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/en/LC_MESSAGES/clisplow.mo \
	${PREFIX}/share/locale/es/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/es/LC_MESSAGES/clisplow.mo \
	${PREFIX}/share/locale/fr/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/fr/LC_MESSAGES/clisplow.mo \
	${PREFIX}/share/locale/nl/LC_MESSAGES/clisp.mo \
	${PREFIX}/share/locale/nl/LC_MESSAGES/clisplow.mo
PROG_PATHS=${PREFIX}/bin/clisp
MAN_PATHS=${PREFIX}/man/man1/clisp.1 ${PREFIX}/man/man3/clreadline.3

# The source doesn't include a top-level Makefile, so we'll fake one.
post-extract:
	@cd ${WRKSRC} && \
	printf "all install:\n\t@cd ${WRKSRC}/${BUILD_DIRNAME} && \$${MAKE} \$${MAKEFLAGS} \$$@\n" > ${WRKSRC}/Makefile

# The 'configure' script stops short of doing this for us.
post-configure:
	cd ${WRKSRC}/${BUILD_DIRNAME} && \
	./makemake ${MAKEMAKE_ARGS} > Makefile && \
	make config.lisp

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PROG_PATHS}
	${CHMOD} -R ugo+rX,ugo-w ${PROG_PATHS}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATA_PATHS}
	${CHMOD} -R ugo+rX,ugo-w ${DATA_PATHS}
	${CHOWN} -R ${MANOWN}:${MANGRP} ${MAN_PATHS}
	${CHMOD} -R ugo+rX,ugo-w ${MAN_PATHS}

MAN1=	clisp.1
MAN3=	clreadline.3

.include <bsd.port.mk>
