# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	visualparadigm
PORTVERSION=	14.1.20170802
CATEGORIES=	devel java
MASTER_SITES=	https://eu5.visual-paradigm.com/visual-paradigm/vpce${PORTVERSION:R}/${PORTVERSION:E}/
DISTNAME=	Visual_Paradigm_CE_${PORTVERSION:C/\./_/g}_Unix_InstallFree

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Visual modeling tool for all kinds of UML diagrams

LICENSE=	VPCEL
LICENSE_NAME=	Visual Paradigm Community Edition License Agreement
LICENSE_FILE=	${WRKSRC}/.install4j/i4j_extf_7_aprh35.txt
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

RUN_DEPENDS=	${LOCALBASE}/lib/libsqlitejdbc.so:java/sqlitejdbc

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_OS=	linux
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${EXTRACT_NAME}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

EXTRACT_NAME=	Visual_Paradigm_CE_${PORTVERSION:R}

post-patch:
	@${FIND} ${WRKSRC} -name *.dll -delete -or -name *.exe -delete -or -name *.orig -delete

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}${BUILD_PREFIX}/Application/bin/Visual_Paradigm* ${STAGEDIR}${DATADIR}/Application/bin
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}${BUILD_PREFIX}/Visual_Paradigm* ${STAGEDIR}${DATADIR}

post-install:
	@${CHMOD} +w ${STAGEDIR}${DATADIR}/Application/bin/vp_windows/ci
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/Application/bin/vp_windows/ci
	@${CHMOD} -w ${STAGEDIR}${DATADIR}/Application/bin/vp_windows/ci

.include <bsd.port.mk>
