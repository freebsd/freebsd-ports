PORTNAME=	eclipse-titan
DISTVERSION=	11.1.0
CATEGORIES=	devel

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TTCN-3 Compilation and Execution Environment
WWW=		https://projects.eclipse.org/projects/tools.titan

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Fails to build, /bin/sh: perl: not found

BUILD_DEPENDS=	bash:shells/bash \
		expect:lang/expect \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		bison:both gmake libedit ssl
USE_LDCONFIG=	${PREFIX}/${TTCN3_DIR}/lib
USE_GCC=	yes
USE_GITLAB=	yes
GL_SITE=	https://gitlab.eclipse.org/eclipse
GL_ACCOUNT=	titan
GL_PROJECT=	titan.core

MAKE_ENV=	TTCN3_DIR=${STAGEDIR}${PREFIX}/${TTCN3_DIR}
MAKE_ARGS=	CXX=${CXX}
MAKE_JOBS_UNSAFE=yes
MANDIRS=	${PREFIX}/${TTCN3_DIR}/man
SUB_FILES=	Makefile.personal \
		${PORTNAME}-man.conf \
		pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} \
		OPENSSLBASE=${OPENSSLBASE} \
		STAGEDIR=${STAGEDIR} \
		CC=${CC} \
		CXX=${CXX} \
		TTCN3_DIR=${TTCN3_DIR} \
		EXAMPLESDIR=${EXAMPLESDIR}
PLIST_SUB=	TTCN3_DIR=${TTCN3_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

TTCN3_DIR=	${PORTNAME}${PKGNAMESUFFIX}

pre-build:
	${INSTALL_DATA} ${WRKDIR}/Makefile.personal ${WRKSRC}
	${REINPLACE_CMD} "s,%%TTCN3_DIR%%,${PREFIX}/${TTCN3_DIR}," \
	    ${WRKSRC}/mctr2/mctr/ttcn3_start

post-install:
	${REINPLACE_CMD} -I "" \
	    "s,TTCN3_DIR =.*,TTCN3_DIR = ${PREFIX}/${TTCN3_DIR}," \
	    ${STAGEDIR}${PREFIX}/${TTCN3_DIR}/demo/Makefile
	${REINPLACE_CMD} -I "" \
	    "s,%%TTCN3_DIR%%,${PREFIX}/${TTCN3_DIR}," \
	    ${STAGEDIR}${PREFIX}/${TTCN3_DIR}/bin/ttcn3_help
	${MV} ${STAGEDIR}${PREFIX}/${TTCN3_DIR}/demo ${STAGEDIR}${EXAMPLESDIR}
	cd ${STAGEDIR}${PREFIX}/${TTCN3_DIR}/man/man1 && \
	    ${RM} ttcn3_compiler.1 && \
	    ${GZIP_CMD} *.1 && \
	    ${LN} -s compiler.1.gz ttcn3_compiler.1.gz
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-man.conf \
	    ${STAGEDIR}${PREFIX}/etc/man.d/${PORTNAME}-man.conf

.include <bsd.port.mk>
