# New ports collection makefile for:	A-A-P Recipe Executive: aap
# Date created:				28 October 2002
# Whom:					Bram Moolenaar <bram@a-a-p.org>
#
# $FreeBSD$
#

PORTNAME=	aap
PORTVERSION=	0.900
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-a-p

MAINTAINER=	bram@a-a-p.org
COMMENT=	A build tool alternative to make with internet access and CVS support

MAN1=		aap.1

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# This port does not need to build anything here
do-build:
	@${TRUE}

# The files are installed in lib/aap/Exec-${PORTVERSION} and below.  Create
# a symbolic link for bin/aap so that it's found in $PATH and still knows
# where to find the Python modules.
# Also create a link for share/doc/aap, so that more people can find the docs
# without clobbering share/doc.
AAPEXECDIR=	lib/aap/Exec-${PORTVERSION}
INSTALLDIR=	${PREFIX}/${AAPEXECDIR}
do-install:
	cd ${WRKSRC} && \
		${MKDIR} -m 755 ${INSTALLDIR}/doc ${INSTALLDIR}/tools && \
		${INSTALL_SCRIPT} *.py aap ${INSTALLDIR} && \
		${INSTALL_SCRIPT} tools/*.py ${INSTALLDIR}/tools && \
		${INSTALL_DATA} -m 644 COPYING README.txt filetype.txt default.aap ${INSTALLDIR} && \
		${INSTALL_DATA} doc/*.html doc/exec.pdf ${INSTALLDIR}/doc && \
		${INSTALL_DATA} aap.1 ${PREFIX}/man/man1 && \
		${LN} -fhs ${INSTALLDIR}/aap ${PREFIX}/bin/aap && \
		${LN} -fhs ${INSTALLDIR}/doc ${PREFIX}/share/doc/aap

post-install:
	@${SED} -e 's,@PYTHON_CMD@,${PYTHON_CMD},g ; \
			s,@AAPEXECDIR@,${AAPEXECDIR},g' \
			< ${FILESDIR}/pkg-install.in > ${WRKSRC}/pkg-install
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${WRKSRC}/pkg-install ${PKGNAME} POST-INSTALL

test:
	cd ${WRKSRC}; ./aap

.include <bsd.port.mk>
