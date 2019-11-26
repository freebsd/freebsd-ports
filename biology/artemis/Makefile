# Created by: camson@bilateral.com.au
# $FreeBSD$

PORTNAME=	artemis
DISTVERSIONPREFIX=	v
DISTVERSION=	17.0.1-11
DISTVERSIONSUFFIX=	-g3e43d27e
CATEGORIES=	biology java

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DNA sequence viewer and annotation tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sanger-pathogens
SHEBANG_FILES=	act art bamview dnaplotter test/*.sh etc/go_associations.pl
USE_JAVA=	yes
ALL_TARGET=	jar
NO_ARCH=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-extract:
	@cd ${WRKDIR} && ${MV} Artemis-${DISTVERSION}${DISTVERSIONSUFFIX} ${PORTNAME}-${DISTVERSION}${DISTVERSIONSUFFIX}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}
.for f in jar_build lib etc images artemis_sqlmap
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}
.endfor
	@cd ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION} && ${MV} jar_build jars
.for f in art act bamview dnaplotter
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}/${f}
	@${REINPLACE_CMD} -i '' -e 's|APPLICATION_HOME=.*|&/jars|' ${STAGEDIR}${PREFIX}/${PORTNAME}-${PORTVERSION}/${f}
	@(${ECHO} "#!/bin/sh"; ${ECHO} ""; ${ECHO} "cd ${PREFIX}/${PORTNAME}-${PORTVERSION} && ./${f}") > ${STAGEDIR}${PREFIX}/bin/${f}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
