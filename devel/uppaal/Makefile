# New ports collection makefile for:   uppaal
# Date created:        16 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	uppaal
PORTVERSION=	4.0.10
CATEGORIES=	devel java linux
DISTNAME=	uppaal-${PORTVERSION}-aca

MAINTAINER=	timbob@bigpond.com
COMMENT=	Tool environment for modeling and verifying timed automata

USE_ZIP=	yes
USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	uppaal verifyta
SUB_LIST+=	PORTNAME=${PORTNAME}
PLIST_SUB+=	PORTNAME=${PORTNAME}
DOWNLOAD_URL=	http://www.it.uu.se/research/group/darts/uppaal/download.shtml
NO_BUILD=	yes

MAN1=		uppaal.1
MANCOMPRESSED=	no

RESTRICTED=	Downloading requires completion of a license agreement

.include <bsd.port.pre.mk>

LINUX_OSRELEASE!=	${ECHO_CMD} `${SYSCTL} -n compat.linux.osrelease 2>/dev/null`

.if ${LINUX_OSRELEASE} == "2.4.2" || ${OSVERSION} < 700000
IGNORE=requires compat.linux.osrelease of at least 2.6.16 (needs 7.0 or later)
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=Please download ${DISTNAME}${EXTRACT_SUFX} into\
${DISTDIR}/${DIST_SUBDIR} from:\n\t${DOWNLOAD_URL}\n
.endif

post-patch:
	${BRANDELF} -t Linux ${WRKSRC}/bin-Linux/server
	${MV} ${WRKSRC}/bin-Linux/server ${WRKSRC}/bin-Linux/server.exe
	${BRANDELF} -t Linux ${WRKSRC}/bin-Linux/verifyta

do-install:
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/bin-Linux/* ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/uppaal.jar ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${JAVASHAREDIR}/${PORTNAME}/lib
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/man/man1/uppaal.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/verifyta ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/uppaal ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
