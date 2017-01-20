# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hgview
PORTVERSION=	1.9.0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP \
		http://download.logilab.org/pub/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Mercurial log navigator written in pyqt4

LICENSE=	GPLv2

RUN_DEPENDS=	hg:devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>0:x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>0:devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}mx-base>0:lang/py-mx-base \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils
BUILD_DEPENDS=	hg:devel/mercurial \
		pyrcc4:textproc/py-qt4-xml \
		xmlto:textproc/xmlto \
		asciidoc:textproc/asciidoc

NO_ARCH=	yes
USE_PYTHON=	distutils
USES=		gmake python:2
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|path/to.*hgview.py|${PYTHON_SITELIBDIR}/hgext/hgview.py|' \
		${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|'make'|'${MAKE_CMD}'|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
