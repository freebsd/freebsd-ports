# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	codeville
PORTVERSION=	0.1.17
CATEGORIES=	devel python
MASTER_SITES=	https://BSDforge.com/projects/source/devel/codeville/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Anarchic control version system without unnecessary re-merges

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:2.7 tar:xz
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTEXAMPLES=	cdvserver.conf.sample

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
