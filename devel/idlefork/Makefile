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
USE_PYDISTUTILS=	yes

pre-install:
	@printf "#!/bin/sh\nexec ${PYTHON_CMD} ${PYTHON_SITELIBDIR}/idlelib/idle.pyc\n" \
		> ${WRKSRC}/idle

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/[^c]*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
