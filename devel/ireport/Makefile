# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	ireport
PORTVERSION=	3.7.6
PORTREVISION=	1
CATEGORIES=	devel databases java
MASTER_SITES=	SF/${PORTNAME}/iReport/iReport-${PORTVERSION}
DISTNAME=	iReport-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual report builder/designer for JasperReports

USES=		dos2unix
USE_JAVA=	yes
DOS2UNIX_GLOB=	*.txt
NO_BUILD=	yes

#LICENSE=	GNU AFFERO GPL
LICENSE_FILE=	${WRKSRC}/LICENSE_ireport.txt

PLIST_SUB=	VER=${PORTVERSION} VERMAN=0.2.0

# Jarfiles to be included in classpath
CLSSPTH=	ant-1.7.1 antlr-2.7.6 asm-attrs asm barbecue-1.5-beta1 \
		barcode4j-2.0 batik-anim batik-awt-util batik-bridge batik-css \
		batik-dom batik-ext batik-gvt batik-parser batik-script \
		batik-svg-dom batik-svggen batik-util batik-xml bcel-5.2 \
		bsh-2.0b4 castor-1.2 cglib-2.1 cincom-jr-xmla \
		commons-beanutils-1.8.2 commons-collections-3.2.1 \
		commons-dbcp-1.2.2 commons-digester-1.7 \
		commons-javaflow-20060411 commons-logging-1.1 commons-math-1.0 \
		commons-pool-1.3 commons-vfs-1.0 dom4j-1.6 ehcache-1.1 \
		eigenbase-properties-1.1.0.10924 eigenbase-resgen-1.3.0.11873 \
		eigenbase-xom-1.3.0.11999 ejb3-persistence groovy-all-1.7.5 \
		hibernate-annotations hibernate-commons-annotations hibernate3 \
		hsqldb-1.8.0-10 iText-2.1.7 iTextAsian jakarta-bcel-20050813 \
		jasperreports-3.7.6 jasperreports-chart-themes-3.7.6 \
		jasperreports-extensions-3.5.3 jasperreports-fonts-3.7.6 \
		javacup javassist-3.4.GA jaxen-1.1.1 jcommon-1.0.15 \
		jdt-compiler-3.1.1 jfreechart-1.0.12 jpa js_activation-1.1 \
		js_axis-1.4patched js_commons-codec-1.3 \
		js_commons-discovery-0.2 js_commons-httpclient-3.1 \
		js_jasperserver-common-ws-3.5.0 js_jaxrpc js_mail-1.4 \
		js_saaj-api-1.3 js_wsdl4j-1.5.1 jta jxl-2.6.10 log4j-1.2.15 \
		mondrian-3.1.1.12687-Jaspersoft olap4j-0.9.7.145 \
		png-encoder-1.5 poi-3.6-20091214 rex-20080421 rhino-1.7R1 \
		saaj-api-1.3 slf4j-api slf4j-log4j12 spring \
		sqleonardo-2009.03.rc1 swingx-2007_10_07 xml-apis-ext xml-apis

# Remark: HSQLDB and Oracle's dependencies already registered by databases/jasperreports
.if exists(${JAVALIBDIR}/classes12.zip)
WITH_ORACLE8=	yes
.endif
.if defined(WITH_ORACLE8)
CLSSORA=	classes12.zip nls_charset12.zip
.endif

.if exists(${JAVALIBDIR}/ojdbc14.jar)
WITH_ORACLE9=	yes
.endif
.if defined(WITH_ORACLE9)
CLSSORA+=	ojdbc14.jar ocrs12.zip
.endif

post-extract:
	${CP} ${FILESDIR}/startup.sh ${WRKSRC}/bin/
	${RM} ${WRKSRC}/bin/*.exe

pre-configure:
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|; \
		s|%%CLSSPTH%%|${CLSSPTH:S,^,${DATADIR}/,g:S,$,.jar£,g}|' \
		-e 's|jar£ |jar\:|g; \
		s|£|:${JAVA_HOME}/lib/tools.jar${CLSSORA:S,^,\:${JAVALIBDIR}/,g}|; \
		s|zip |zip|g; s|jar |jar|g' \
		-e 's|%%JAVA_HOME%%|${JAVA_HOME}|; \
		s|%%DATADIR%%|${DATADIR}|g; \
		s|^java |${LOCALBASE}/bin/java |' \
		${WRKSRC}/bin/startup.sh
	${REINPLACE_CMD} -e 's|/bin/grep|/usr/bin/grep|' \
		${WRKSRC}/platform9/lib/nbexec

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/startup.sh
	${LN} -sf ${DATADIR}/bin/startup.sh ${STAGEDIR}${PREFIX}/bin/iReport

.include <bsd.port.mk>
