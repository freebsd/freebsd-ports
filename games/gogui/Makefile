PORTNAME=	gogui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.10
CATEGORIES=	games java
MASTER_SITES=	http://www.randelshofer.ch/quaqua/files/:quaqua
DISTFILES=	quaqua-5.2.1.nested.zip:quaqua

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI for programs that play Go through Go Text Protocol (GTP)

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl

USE_GITHUB=	yes
GH_ACCOUNT=	lemonsqueeze
USE_JAVA=	yes
USE_ANT=	yes

MAKE_ARGS+=	-Ddocbook-xsl.dir=${LOCALBASE}/share/xsl/docbook

NO_ARCH=	yes

GOGUI_JARS=	gogui-adapter gogui-convert gogui-dummy gogui-server gogui-terminal gogui-twogtp \
		gogui-client gogui-display gogui-regress gogui-statistics gogui-thumbnailer gogui

PLIST_FILES=	${GOGUI_JARS:C/^/bin\//} ${GOGUI_JARS:C/^/${JAVAJARDIR}\//:C/$$/.jar/} ${JAVAJARDIR}/quaqua.jar

post-extract:
	@cd ${WRKDIR} && \
		unzip quaqua-5.2.1.zip && \
		${MKDIR} ${WRKSRC}/lib && \
		${MV} Quaqua/dist/quaqua.jar ${WRKSRC}/lib

post-patch:
	@${REINPLACE_CMD} 's|/usr/share|${LOCALBASE}/share|' ${WRKSRC}/build.xml

do-install:
.for j in ${GOGUI_JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${j}.jar ${STAGEDIR}${JAVAJARDIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${JAVA} -jar ${JAVAJARDIR}/${j}.jar" \
	) > ${STAGEDIR}${PREFIX}/bin/${j}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${j}
.endfor
	${INSTALL_DATA} ${WRKSRC}/lib/quaqua.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
