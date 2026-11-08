PORTNAME=	abcl
PORTVERSION=	1.10.0
CATEGORIES=	lang lisp java
MASTER_SITES=	http://abcl.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Implementation of ANSI Common Lisp in Java
WWW=		https://common-lisp.net/project/armedbear/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to build: build.xml: Java returned: 1
BROKEN_armv7=	fails to build: build.xml: Java returned: 1

USES=		java:ant,run

SUB_FILES=	abcl
SUB_LIST+=	JAVAJARDIR="${JAVAJARDIR}"

PLIST_FILES=	bin/abcl \
		share/java/classes/abcl-contrib.jar \
		share/java/classes/abcl.jar

do-install:
	${INSTALL_DATA} -v ${WRKSRC}/dist/abcl.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} -v ${WRKSRC}/dist/abcl-contrib.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/abcl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
