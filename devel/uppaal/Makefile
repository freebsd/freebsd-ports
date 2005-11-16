# New ports collection makefile for:   uppaal
# Date created:        16 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	uppaal
PORTVERSION=	3.4.11
CATEGORIES=	devel java linux
DISTNAME=	${PORTNAME}

MAINTAINER=	timbob@bigpond.com
COMMENT=	Tool environment for modeling and verifying timed automata

USE_ZIP=	yes
USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_RUN=	yes

SUB_FILES=	uppaal verifyta
SUB_LIST+=	PORTNAME=${PORTNAME}
PLIST_SUB+=	PORTNAME=${PORTNAME}
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		uppaal.1
MANCOMPRESSED=	no

RESTRICTED=	"Downloading requires completion of a license agreement"

.include <bsd.port.pre.mk>
TO_BE_FETCHED=
.for f in ${DISTFILES}
.if ! exists (${DISTDIR}/${DIST_SUBDIR}/${f})
TO_BE_FETCHED+=		${f}
.endif
.endfor

do-fetch:
.if ${TO_BE_FETCHED} != ""
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\n\
------------------------------------------------------------------\n\
Downloading this software requires completion of a licence\n\
agreement, which may be found at: http://www.uppaal.com\n\
\n\
Please download the _latest_ versions of the following files into\n\
${DISTDIR}/${DIST_SUBDIR}\n\
\n
.for f in ${TO_BE_FETCHED}
IGNORE+=	${f}\n
.endfor
IGNORE+=------------------------------------------------------------------\n\n
.endif

post-patch:
	${BRANDELF} -t Linux ${WRKSRC}/bin-Linux/server
	${MV} ${WRKSRC}/bin-Linux/server ${WRKSRC}/bin-Linux/server.exe
	${BRANDELF} -t Linux ${WRKSRC}/bin-Linux/socketserver
	${MV} ${WRKSRC}/bin-Linux/socketserver ${WRKSRC}/bin-Linux/socketserver.exe
	${BRANDELF} -t Linux ${WRKSRC}/bin-Linux/verifyta

do-install:
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}/lib
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/License-ASF ${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin-Linux/* ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/uppaal2k.jar ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${JAVASHAREDIR}/${PORTNAME}/lib
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${JAVASHAREDIR}/${PORTNAME}/demo
	${INSTALL_MAN} ${WRKSRC}/man/man1/uppaal.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/verifyta ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/uppaal ${PREFIX}/bin

.include <bsd.port.post.mk>
