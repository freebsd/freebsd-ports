# New ports collection makefile for:    idlefork
# Date created:         		9 August 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	idlefork
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	@printf "#!/bin/sh\nexec ${PYTHON_CMD} ${PREFIX}/lib/${PYTHON_VERSION}/site-packages/idlelib/idle.pyc\n" \
		> ${WRKSRC}/idle
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/[^c]*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
