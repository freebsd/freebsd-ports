# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	visualparadigm
PORTVERSION=	12.0.20150401
CATEGORIES=	devel
MASTER_SITES=	http://eu6.visual-paradigm.com/visual-paradigm/vpce12.0/20150401/
DISTNAME=	Visual_Paradigm_CE_12_0_20150401_Unix_InstallFree

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Visual modeling tool for all kinds of UML diagrams

USE_JAVA=	yes
JAVA_VERSION=	1.8+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${PORTNAME}

EXTRACT_NAME=	Visual_Paradigm_CE_12.0

FETCH_ARGS=	-Fpr

post-patch:
	${FIND} ${WRKSRC} -name *.dll -delete -or -name *.exe -delete -or -name *.orig -delete

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}/${EXTRACT_NAME} && ${COPYTREE_SHARE} \* ${INSTALLDIR} && ${CP} -R .install4j ${INSTALLDIR}

post-install:
	${CHMOD} 755 ${INSTALLDIR}/Application/bin/V*
	${CHMOD} 755 ${INSTALLDIR}/Visual_Paradigm

.include <bsd.port.mk>
