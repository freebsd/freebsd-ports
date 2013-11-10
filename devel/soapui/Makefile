# Created by: arved
# $FreeBSD$

PORTNAME=	soapui
PORTVERSION=	4.6.1
CATEGORIES=	devel java www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	SoapUI-${PORTVERSION}-linux-bin

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Web service, SOA, and SOAP testing tool

LICENSE=	GPLv2

USE_JAVA=	1.6+
WRKSRC=		${WRKDIR}/SoapUI-${PORTVERSION}
REINPLACE_ARGS=	-i ''
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|\(SOAPUI_HOME=\).*$$|\1${DATADIR}| ; \
		/-Dsoapui\.jxbrowser\.disable=true/s/^#// ; \
		s|^java |exec ${JAVA} | ; /^cd $$DIRNAME/d' ${WRKSRC}/bin/*.sh

.include <bsd.port.options.mk>

do-install:
.for dir in bin lib
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Tutorials ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.	for i in README.md RELEASENOTES.txt
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.	endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} licenses ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
