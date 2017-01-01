# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=		bazel
PORTVERSION=		0.4.2r # rc2 of 0.4.2
CATEGORIES=		devel java
MASTER_SITES=		https://storage.googleapis.com/bazel/0.4.2/rc2/
DISTNAME=		bazel-0.4.2rc2-dist

MAINTAINER=		aehlig@linta.de
COMMENT=		Fast and correct build system

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=		bash:shells/bash \
			zip:archivers/zip

NO_WRKSUBDIR=		YES
USES=			shebangfix zip
SHEBANG_FILES=		${WRKSRC}/tools/cpp/link_dynamic_library.sh
USE_JAVA=		yes
JAVA_VENDOR=		openjdk
JAVA_VERSION=		1.8
JAVA_BUILD=		yes
JAVA_RUN=		yes

PLIST_FILES=		bin/bazel

do-build:
	@${MKDIR} ${WRKDIR}/bazel_tmp
	(cd ${WRKSRC} && \
	${SETENV} BAZEL_SH=${LOCALBASE}/bin/bash \
	TMPDIR=${WRKDIR}/bazel_tmp \
	${LOCALBASE}/bin/bash ./compile.sh)

do-install:
	@${CP} ${WRKSRC}/output/bazel ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
