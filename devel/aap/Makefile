# New ports collection makefile for:	A-A-P Recipe Executive: aap
# Date created:				28 October 2002
# Whom:					Bram Moolenaar <bram@a-a-p.org>
#
# $FreeBSD$
#

PORTNAME=	aap
PORTVERSION=	0.111
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-a-p
DISTNAME=	exec-${PORTVERSION}

MAINTAINER=	bram@a-a-p.org

# A-A-P requires an "scp" command.  If it doesn't exist, we need to chose which
# one to install.  The OpenSSH one is probably the best choice.
RUN_DEPENDS=	scp:${PORTSDIR}/security/openssh

MAN1=		aap.1

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# There is no Makefile for A-A-P; do the building and installing here.
#
# Building means compiling the Python files so that the .pyc and .pyo files are
# generated.
do-build:
	cd ${WRKSRC}; ${PYTHON_CMD} -c "import compileall; compileall.compile_dir('.', 0)"
	cd ${WRKSRC}; ${PYTHON_CMD} -O -c "import compileall; compileall.compile_dir('.', 0)"

# The files are installed in lib/aap/Exec-${PORTVERSION} and below.  Create
# a symbolic link for bin/aap so that it's found in $PATH and still knows
# where to find the Python modules.
# Also create a link for share/doc/aap, so that more people can find the docs
# without clobbering share/doc.
do-install:
	${MKDIR} -m 0755 ${PREFIX}/lib/aap/Exec-${PORTVERSION}/doc
	cd ${WRKSRC}; ${INSTALL_SCRIPT} *.py *.pyc *.pyo aap ${PREFIX}/lib/aap/Exec-${PORTVERSION}
	cd ${WRKSRC}; ${INSTALL_DATA} -m 0744 COPYING README.txt filetype.txt default.aap ${PREFIX}/lib/aap/Exec-${PORTVERSION}
	cd ${WRKSRC}; ${INSTALL_DATA} doc/*.html doc/exec.pdf ${PREFIX}/lib/aap/Exec-${PORTVERSION}/doc
	cd ${WRKSRC}; ${INSTALL_DATA} aap.1 ${PREFIX}/man/man1
	cd ${PREFIX}/bin; ${LN} -fhs ../lib/aap/Exec-${PORTVERSION}/aap aap
	cd ${PREFIX}/share/doc; ${LN} -fhs ../../lib/aap/Exec-${PORTVERSION}/doc aap

test:
	cd ${WRKSRC}; ./aap

.include <bsd.port.mk>
