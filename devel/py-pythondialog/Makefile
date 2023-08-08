PORTNAME=	pythondialog
PORTVERSION=	3.5.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Python interface to dialog(3)
WWW=		http://pythondialog.sourceforge.net/

LICENSE=	LGPL21+

RUN_DEPENDS=	cdialog:devel/cdialog

USES=		python
USE_PYTHON=	autoplist concurrent distutils

PORTEXAMPLES=	*
REINPLACE_ARGS=	-i ""

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	# devel/cdialog installs dialog as cdialog not to conflict
	# with dialog(1).
	${FIND} ${WRKSRC} -type f | \
	    ${XARGS} ${REINPLACE_CMD} -e 's|dialog="dialog"|dialog="cdialog"|g'

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
