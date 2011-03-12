# New ports collection makefile for:	py-virtualenv
# Date created:		2007-10-10
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtualenv
PORTVERSION=	1.5.2
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Virtual Python Environment builder

PLIST_SUB=	PYVER=${PYTHON_VER} PIPVER=${PIPVER} DISTRIBUTEVER=${DISTRIBUTEVER}

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

PIPVER=	0.8.3
DISTRIBUTEVER=	0.6.14

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${INSTALL_DATA} index.txt ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 270

SETUPTOOLS27_EGG=	setuptools-0.6c11-py2.7.egg
MASTER_SITES+=	http://pypi.python.org/packages/2.7/s/setuptools/:st27
DISTFILES+=	${SETUPTOOLS27_EGG}:st27

post-patch:
	${CP} ${DISTDIR}/${SETUPTOOLS27_EGG} ${WRKSRC}/virtualenv_support/

.endif

.include <bsd.port.post.mk>
