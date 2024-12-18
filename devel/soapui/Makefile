PORTNAME=	soapui
PORTVERSION=	5.5.0
CATEGORIES=	devel java www
MASTER_SITES=	https://s3.amazonaws.com/downloads.eviware/soapuios/${PORTVERSION}/
DISTNAME=	SoapUI-${PORTVERSION}-linux-bin

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Web service, SOA, and SOAP testing tool
WWW=		https://www.soapui.org

LICENSE=	APACHE11 APACHE20 BSD3CLAUSE CPL EUPL11 LGPL21 LGPL3 MIT MPL11
LICENSE_COMB=	multi

LICENSE_NAME_CPL=	Common Public License V. 1.0
LICENSE_FILE_CPL=	${WRKSRC}/licenses/junit-LICENSE.txt
LICENSE_FILE_EUPL11=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_CPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe
CPE_VENDOR=	smartbear
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/SoapUI-${PORTVERSION}
REINPLACE_ARGS=	-i ''
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|\(SOAPUI_HOME=\).*$$|\1${DATADIR}| ; \
		/-Dsoapui\.jxbrowser\.disable=true/s/^#// ; \
		s|^java |exec ${JAVA} | ; /^cd $$DIRNAME/d' ${WRKSRC}/bin/*.sh

do-install:
.for dir in bin lib
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Tutorials ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README.md RELEASENOTES.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} licenses ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
