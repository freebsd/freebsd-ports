# New ports collection makefile for:    idle
# Date created:         		13 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	idle
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.python.org/idle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
PYTHON_VERSION=	python1.5

do-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
		@${MKDIR} ${PREFIX}/share/idle/Icons
		@cd ${WRKSRC} && \
			${INSTALL_DATA} *.py? help.txt ${PREFIX}/share/idle
		@${INSTALL_DATA} ${WRKSRC}/Icons/* ${PREFIX}/share/idle/Icons
		@printf "#!/bin/sh\n${PYTHON_CMD} ${PREFIX}/share/idle/idle.pyc\n" \
			> ${WRKDIR}/idle.sh
		@${INSTALL_SCRIPT} ${WRKDIR}/idle.sh ${PREFIX}/bin/idle
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/idle
		@cd ${WRKSRC} && ${INSTALL_DATA} NEWS.txt README.txt TODO.txt \
			extend.txt ${PREFIX}/share/doc/idle
.endif

.include <bsd.port.mk>
