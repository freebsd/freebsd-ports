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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An official experimental development fork of IDE for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

DEPRECATED=	"has been integrated into Pyhton 2.3+"
IGNORE=		${DEPRECATED}
EXPIRATION_DATE=2005-06-01

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

pre-install:
	@${PRINTF} "#!/bin/sh\nexec ${PYTHON_CMD} ${PYTHON_SITELIBDIR}/idlelib/idle.pyc\n" \
		> ${WRKSRC}/idle

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/[^c]*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
