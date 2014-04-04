# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hgview
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LOGILAB

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Mercurial log navigator written in pyqt4

RUN_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}qt4-qscintilla2>0:${PORTSDIR}/devel/py-qt4-qscintilla2 \
		${PYTHON_PKGNAMEPREFIX}mx-base>0:${PORTSDIR}/lang/py-mx-base \
		${PYTHON_PKGNAMEPREFIX}docutils>0:${PORTSDIR}/textproc/py-docutils
BUILD_DEPENDS=	hg:${PORTSDIR}/devel/mercurial \
		pyrcc4:${PORTSDIR}/textproc/py-qt4-xml \
		xmlto:${PORTSDIR}/textproc/xmlto \
		asciidoc:${PORTSDIR}/textproc/asciidoc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USES=		gmake
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/python-support/mercurial-common|${PYTHON_SITELIBDIR:C,^${PYTHONBASE}/,,}|' \
		${WRKSRC}/hgviewlib/__pkginfo__.py
	@${FIND} ${WRKSRC} -name __pkginfo__.py | ${XARGS} \
		${REINPLACE_CMD} -e 's|share/man|man|'
	@${REINPLACE_CMD} -e 's|path/to.*hgview.py|${PYTHON_SITELIBDIR}/hgext/hgview.py|' \
		${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|'make'|'${GMAKE}'|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
