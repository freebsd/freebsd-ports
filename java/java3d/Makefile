# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	java3d
PORTVERSION=	1.5.2
PORTREVISION=	4
CATEGORIES=	java graphics games devel
MASTER_SITES=	https://sites.google.com/site/daemonwizard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides API for creating and manipulation of 3D geometry

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		tar:bzip2
USE_JAVA=	yes
USE_GL=		gl
USE_XORG=	xt
JAVA_VERSION=	1.6+
JAVA_VENDOR=	openjdk
USE_ANT=	yes

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/^${PREFIX}\///} ARCH=${ARCH}

DOCSSRC=	${WRKSRC}/j3d-core/build/freebsd/javadocs/docs-public
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' \
		${WRKSRC}/j3d-core/src/native/ogl/build-freebsd.xml

do-build:
	cd ${WRKSRC}/vecmath && ${SETENV} ${MAKE_ENV} ${ANT} dist
	cd ${WRKSRC}/j3d-core \
		&& ${SETENV} ${MAKE_ENV} ${ANT} -Dbuild.type=fcs \
						-Dis${OPSYS}=yes \
						-Dports.localbase=${LOCALBASE} \
						jar-opt

post-build-DOCS-on:
	cd ${WRKSRC}/j3d-core \
		&& ${SETENV} ${MAKE_ENV} ${ANT} -Dbuild.type=fcs \
						-Dis${OPSYS}=yes \
						docs-public

do-install:
	@${MKDIR} ${STAGEDIR}${JAVA_HOME}/jre/lib/ext
	${INSTALL_DATA} \
		${WRKSRC}/vecmath/dist/lib/ext/vecmath.jar \
		${WRKSRC}/j3d-core/build/default/opt/lib/ext/j3dcore.jar \
		${WRKSRC}/j3d-core/build/default/opt/lib/ext/j3dutils.jar \
		${STAGEDIR}${JAVA_HOME}/jre/lib/ext
	@${MKDIR} ${STAGEDIR}${JAVA_HOME}/jre/lib/${ARCH}
	${INSTALL} \
		${WRKSRC}/j3d-core/build/default/opt/native/libj3dcore-ogl.so \
		${STAGEDIR}${JAVA_HOME}/jre/lib/${ARCH}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${DOCSSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
