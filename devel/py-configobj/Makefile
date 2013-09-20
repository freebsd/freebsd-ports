# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	configobj
PORTVERSION=	4.7.2
CATEGORIES=	devel python
MASTER_SITES=	http://www.voidspace.org.uk/downloads/ \
		SF \
		${MASTER_SITE_GOOGLE_CODE}

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple but powerful config file reader and writer

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
