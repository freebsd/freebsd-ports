# New ports collection makefile for:   py-coil
# Date created:        13 April 2010
# Whom:                ghostonthewire <ghostonthewire at gmail dot com>
#
# $FreeBSD$
#

PORTNAME=	coil
PORTVERSION=	0.3.12
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ghostonthewire@gmail.com
COMMENT=	A powerful configuration language for Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PORTDOCS=	LICENSE.txt \
		README.txt \
		TODO.txt

post-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/coil/*
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/coil/*

.include <bsd.port.mk>
