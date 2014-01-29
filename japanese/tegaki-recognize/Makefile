# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	tegaki
PORTVERSION=	0.3.1.2
CATEGORIES=	japanese python
MASTER_SITES=	http://www.tegaki.org/releases/${PORTVERSION:.2=}/
PKGNAMESUFFIX=	-recognize
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open-Source Chinese and Japanese Handwriting Recognition

LICENSE=	GPLv2

LIB_DEPENDS=	libzinnia.so:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/tegakigtk/recognizer.py:${PORTSDIR}/japanese/py-tegaki-gtk

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}_recognize

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
