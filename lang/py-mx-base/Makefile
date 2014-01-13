# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mx-base
PORTVERSION=	3.2.6
CATEGORIES=	lang python
MASTER_SITES=	https://downloads.egenix.com/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	eGenix mx-Extension Series for Python

USE_PYTHON=	2
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	egenix-mx-base

PORTDOCS=	COPYRIGHT MANIFEST README LICENSE PKG-INFO
ADDITIONAL_DOCS=	mx/DateTime/Doc/mxDateTime.pdf \
			mx/Proxy/Doc/mxProxy.pdf \
			mx/Queue/Doc/mxQueue.pdf \
			mx/Stack/Doc/mxStack.pdf \
			mx/TextTools/Doc/mxTextTools.pdf \
			mx/Tools/Doc/mxTools.pdf \
			mx/BeeBase/Doc/mxBeeBase.pdf \
			mx/URL/Doc/mxURL.pdf \
			mx/UID/Doc/mxUID.pdf

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	DOCS ZOPE EXAMPLES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZOPE}
USES=		zope
.endif

post-patch:
	@${REINPLACE_CMD} -e '/pdf/d' ${WRKSRC}/egenix_mx_base.py
	@${REINPLACE_CMD} -e '/Examples/d' ${WRKSRC}/egenix_mx_base.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${ADDITIONAL_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCSDIR}/index.html
	@${CHMOD} 644 ${DOCSDIR}/index.html
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/mx/DateTime
	@${INSTALL_DATA} ${WRKSRC}/mx/DateTime/Examples/* ${EXAMPLESDIR}/mx/DateTime
	@${MKDIR} ${EXAMPLESDIR}/mx/TextTools
	@${INSTALL_DATA} ${WRKSRC}/mx/TextTools/Examples/* ${EXAMPLESDIR}/mx/TextTools
	@${MKDIR} ${EXAMPLESDIR}/mx/Tools
	@${INSTALL_DATA} ${WRKSRC}/mx/Tools/Examples/* ${EXAMPLESDIR}/mx/Tools
.endif
.include <bsd.port.mk>
