# $FreeBSD$

PORTNAME=	vdbench
PORTVERSION=	5.04.07
CATEGORIES=	benchmarks linux java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Command line disk I/O benchmark utility

LICENSE=	OTN
LICENSE_NAME=	Oracle Technology Network
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	none

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Linux compatibility layer only supports i386/amd64

USES=		linux shebangfix uniquefiles:dirs zip
USE_JAVA=	yes

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
JAVA_OS=	linux
NO_BUILD=	yes
PLIST_SUB=	LINUX_ARCH=${LINUX_ARCH}
SHEBANG_FILES=	${PORTNAME} linux/config.sh
bash_CMD=	${SH}

OPTIONS_DEFINE=	DOCS EXAMPLES

DOWNLOAD_URL=	https://www.oracle.com/technetwork/server-storage/vdbench-downloads-1901681.html

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually download ${DISTFILES} from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again
.endif

.if ${ARCH} == i386
LINUX_ARCH=	32
.endif

.if ${ARCH} == amd64
LINUX_ARCH=	64
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^java=java|java=${JAVA_HOME}/bin/java|' \
	-e 's|^dir=.*|dir=${DATADIR}|' ${WRKSRC}/vdbench

	${REINPLACE_CMD} -e 's|/proc/meminfo|/compat/proc/meminfo|' \
	-e '/^free/d' ${WRKSRC}/linux/config.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/linux
	for f in vdbench.jar build_sds.txt swatcharts.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${STAGEDIR}${DATADIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/linux/linux${LINUX_ARCH}.so ${STAGEDIR}${DATADIR}/linux
	${INSTALL_SCRIPT} ${WRKSRC}/linux/config.sh ${STAGEDIR}${DATADIR}/linux
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${RLN} ../${DATADIR_REL}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in vdbench.pdf readme.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${STAGEDIR}${DOCSDIR}; \
	done

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}; ${COPYTREE_SHARE} examples ${STAGEDIR}${EXAMPLESDIR})
	for e in $$(${JOT} - 1 7); do \
		${INSTALL_DATA} ${WRKSRC}/example$${e} ${STAGEDIR}${EXAMPLESDIR}; \
	done

.include <bsd.port.post.mk>
