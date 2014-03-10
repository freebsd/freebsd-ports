# Created by: Eugene Mychlo <myc@barev.net>
# $FreeBSD$

PORTNAME=	yed
PORTVERSION=	3.12
CATEGORIES=	graphics java
MASTER_SITES=	#
DISTNAME=	yEd-${PORTVERSION}

MAINTAINER=	myc@barev.net
COMMENT=	Editor for graphs and diagrams

LICENSE=	YED_1_1
LICENSE_NAME=	yEd Software License Agreement (Version 1.1)
LICENSE_TEXT=	Description of the license can be obtained from the following URL: \
		http://www.yworks.com/products/yed/license.html
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
RESTRICTED=	Downloading requires acceptance of license agreement
DESKTOP_ENTRIES="yEd" "${COMMENT}" "" "yed" "" false

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	${PORTNAME}

DOWNLOAD_URL?=	http://www.yworks.com/en/products_download.php?file=${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	you must manually obtain ${DISTNAME}${EXTRACT_SUFX} from\
	'${DOWNLOAD_URL}', place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/license.html ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/vectorgraphics.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
