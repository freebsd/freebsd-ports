# New ports collection makefile for:    pychecker
# Date created:         		13 April 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pychecker
PORTVERSION=	0.2.5
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/pychecker
DOCS=		README TODO KNOWN_BUGS VERSION MAINTAINERS CHANGELOG COPYRIGHT

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${INSTDIR}
.for suff in py pyc pyo
	@${INSTALL_DATA} ${WRKSRC}/*.${suff} ${INSTDIR}
.endfor
	@printf '#!/bin/sh\n${PYTHON_CMD} ${INSTDIR}/checker.py "$$@"\n' \
		> ${WRKDIR}/pychecker.sh
	@${MKDIR} ${PREFIX}/share/doc/pychecker
.for file in ${DOCS}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/pychecker
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/pychecker.sh ${PREFIX}/bin/pychecker

.include <bsd.port.mk>
