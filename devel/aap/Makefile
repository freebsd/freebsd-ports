# New ports collection makefile for:	A-A-P Recipe Executive: aap
# Date created:				28 October 2002
# Whom:					Bram Moolenaar <bram@a-a-p.org>
#
# $FreeBSD$
#

PORTNAME=	aap
PORTVERSION=	0.900
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-a-p

MAINTAINER=	bram@a-a-p.org
COMMENT=	A build tool alternative to make with internet access and CVS support

MAN1=		aap.1

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# The files are installed in lib/aap/Exec-${PORTVERSION} and below.  Create
# a symbolic link for bin/aap so that it's found in $PATH and still knows
# where to find the Python modules.
# Also create a link for share/doc/aap, so that more people can find the docs
# without clobbering share/doc.
INSTALLDIR=	${PREFIX}/lib/aap/Exec-${PORTVERSION}
do-install:
	cd ${WRKSRC} && \
		${MKDIR} -m 755 ${INSTALLDIR}/tools && \
		${INSTALL_SCRIPT} *.py aap ${INSTALLDIR} && \
		${LN} -fhs ${INSTALLDIR}/aap ${PREFIX}/bin/aap && \
		${INSTALL_SCRIPT} tools/*.py ${INSTALLDIR}/tools && \
		${INSTALL_DATA} -m 644 COPYING README.txt default.aap ${INSTALLDIR} && \
		${INSTALL_DATA} aap.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && \
		${MKDIR} -m 755 ${INSTALLDIR}/doc ${INSTALLDIR}/doc/html && \
		${INSTALL_DATA} filetype.txt doc/exec.pdf ${INSTALLDIR}/doc && \
		${INSTALL_DATA} doc/*.html ${INSTALLDIR}/doc/html && \
		${LN} -fhs ${INSTALLDIR}/doc ${PREFIX}/share/doc/aap
.endif
	cd ${INSTALLDIR} && \
		${PYTHON_CMD} -c "import compileall; compileall.compile_dir('.', 1)"

test: install
	cd ${WRKSRC}; ${PREFIX}/bin/aap

.include <bsd.port.mk>
