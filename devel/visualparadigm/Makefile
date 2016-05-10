# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	visualparadigm
PORTVERSION=	13.1.20160502
CATEGORIES=	devel
MASTER_SITES=	http://eu6.visual-paradigm.com/visual-paradigm/vpce${PORTVERSION:R}/${PORTVERSION:E}/
DISTNAME=	Visual_Paradigm_CE_${PORTVERSION:C/\./_/g}_Unix_InstallFree

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Visual modeling tool for all kinds of UML diagrams

RUN_DEPENDS=	${LOCALBASE}/lib/libsqlitejdbc.so:java/sqlitejdbc

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_OS=	linux
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${PORTNAME}

EXTRACT_NAME=	Visual_Paradigm_CE_13.1

FETCH_ARGS=	-Fpr

post-patch:
	@${FIND} ${WRKSRC} -name *.dll -delete -or -name *.exe -delete -or -name *.orig -delete

do-install:
	@${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}/${EXTRACT_NAME} && ${COPYTREE_SHARE} \* ${INSTALLDIR} && ${CP} -R .install4j ${INSTALLDIR}

.include <bsd.port.mk>
