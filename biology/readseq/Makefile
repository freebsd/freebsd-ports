PORTNAME=	readseq
DISTVERSION=	2.1.19
CATEGORIES=	biology java
# The site used by bioconda for 2.1.30 is down as of 2021-04-13
# MASTER_SITES=	http://iubio.bio.indiana.edu/soft/molbio/readseq/java/
MASTER_SITES=	https://sourceforge.net/projects/readseq/files/latest/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.jar

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Read and reformat biosequences, Java command-line version

LICENSE=	PD

USE_JAVA=	yes
NO_BUILD=	yes
SUB_FILES=	readseq
PLIST_FILES=	bin/readseq share/java/classes/readseq.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/readseq ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
