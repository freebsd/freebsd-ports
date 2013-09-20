# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	darcsver
PORTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generate a version number from darcs history

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's#(doc_loc, data_fnames)##g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${CP} README.rst ${DOCSDIR}/
.endif

.include <bsd.port.mk>
