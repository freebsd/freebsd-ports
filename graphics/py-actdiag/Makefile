# New ports collection makefile for:	py-actdiag
# Date created:		2011-08-07
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	actdiag
PORTVERSION=	0.1.7
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A simple activity-diagram image generator

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PKGNAMEPREFIX}blockdiag>=0.8.1:${PORTSDIR}/graphics/py-blockdiag

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
PORTDOCS=	README.txt

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/src/${PORTDOCS} ${DOCSDIR}
.endif

x-generate-plist:
	${ECHO} bin/${PORTNAME} > pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type f | ${SORT} | \
	${SED} -e 's,${PYTHON_SITELIBDIR},%%PYTHON_SITELIBDIR%%,' \
		-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' \
		>> pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type d -depth | ${SORT} -r | \
	${SED} -e 's,${PYTHON_SITELIBDIR},@dirrm %%PYTHON_SITELIBDIR%%,' \
		-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' \
		>> pkg-plist.new

.include <bsd.port.mk>
