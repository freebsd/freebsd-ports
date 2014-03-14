# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mx-base
PORTVERSION=	3.2.6
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	https://downloads.egenix.com/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	eGenix mx-Extension Series for Python

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONSFILE=		${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=		DOCS ZOPE EXAMPLES
ZOPE_USES=		zope

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

.include <bsd.port.mk>
