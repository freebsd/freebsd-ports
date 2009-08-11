# New ports collection makefile for:	java3d
# Date created:				2003/12/19
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	java3d
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	java graphics
MASTER_SITES=	http://daemon.wizard.googlepages.com/
DISTNAME=	java3d-${PORTVERSION}

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Java3D Kit ${PORTVERSION}

USE_BZIP2=	yes

USE_JAVA=	yes
USE_GL=		gl
USE_XORG=	xt
JAVA_VERSION=	1.5+
JAVA_VENDOR=	freebsd bsdjava
USE_ANT=	yes

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/^${PREFIX}\///} ARCH=${ARCH}

.if !defined(NOPORTDOCS)
DOCSSRC=	${WRKSRC}/j3d-core/build/freebsd/javadocs/docs-public
PORTDOCS=	*
.endif

do-build:
	cd ${WRKSRC}/vecmath && ${ANT} dist
	cd ${WRKSRC}/j3d-core && ${ANT} -Dbuild.type=fcs -Dis${OPSYS}=yes -Dports.localbase=${LOCALBASE} jar-opt
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/j3d-core && ${ANT} -Dbuild.type=fcs -Dis${OPSYS}=yes docs-public
.endif

do-install:
	${INSTALL_DATA} \
		${WRKSRC}/vecmath/dist/lib/ext/vecmath.jar \
		${WRKSRC}/j3d-core/build/default/opt/lib/ext/j3dcore.jar \
		${WRKSRC}/j3d-core/build/default/opt/lib/ext/j3dutils.jar \
		${JAVA_HOME}/jre/lib/ext
	${INSTALL} \
		${WRKSRC}/j3d-core/build/default/opt/native/libj3dcore-ogl.so \
		${JAVA_HOME}/jre/lib/${ARCH}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${DOCSSRC} && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
