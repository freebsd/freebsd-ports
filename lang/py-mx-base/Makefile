# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mx-base
PORTVERSION=	3.2.9
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://downloads.egenix.com/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	eGenix mx-Extension Series for Python

LICENSE=	EGENIX
LICENSE_NAME=	EGENIX.COM Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	egenix-mx-base
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-py${PYTHON_VER}-nspkg.pth

OPTIONS_DEFINE=		DOCS EXAMPLES

TXTDOCS=	COPYRIGHT MANIFEST README LICENSE PKG-INFO
PDFDOCS=	mx/DateTime/Doc/mxDateTime.pdf \
		mx/Proxy/Doc/mxProxy.pdf \
		mx/Queue/Doc/mxQueue.pdf \
		mx/Stack/Doc/mxStack.pdf \
		mx/TextTools/Doc/mxTextTools.pdf \
		mx/Tools/Doc/mxTools.pdf \
		mx/BeeBase/Doc/mxBeeBase.pdf \
		mx/URL/Doc/mxURL.pdf \
		mx/UID/Doc/mxUID.pdf
PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e '/pdf/d' ${WRKSRC}/egenix_mx_base.py
	@${REINPLACE_CMD} -e '/Examples/d' ${WRKSRC}/egenix_mx_base.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${TXTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PDFDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${STAGEDIR}${DOCSDIR}/index.html
	@${CHMOD} 644 ${STAGEDIR}${DOCSDIR}/index.html

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/mx/DateTime
	${INSTALL_DATA} ${WRKSRC}/mx/DateTime/Examples/* ${STAGEDIR}${EXAMPLESDIR}/mx/DateTime
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/mx/TextTools
	${INSTALL_DATA} ${WRKSRC}/mx/TextTools/Examples/* ${STAGEDIR}${EXAMPLESDIR}/mx/TextTools
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/mx/Tools
	${INSTALL_DATA} ${WRKSRC}/mx/Tools/Examples/* ${STAGEDIR}${EXAMPLESDIR}/mx/Tools

	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/DateTime/mxDateTime/mxDateTime.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/BeeBase/mxBeeBase/mxBeeBase.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/Proxy/mxProxy/mxProxy.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/UID/mxUID/mxUID.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/Stack/mxStack/mxStack.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/URL/mxURL/mxURL.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/TextTools/mxTextTools/mxTextTools.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/Tools/mxTools/mxTools.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/mx/Queue/mxQueue/mxQueue.so

.include <bsd.port.mk>
