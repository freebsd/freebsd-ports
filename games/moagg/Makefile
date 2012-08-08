# New Ports collection makefile for:	moagg
# Date created:		03 August 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	moagg
PORTVERSION=	1.95b
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${DISTVERSION:S/b//}/ \
		http://moagg.sourceforge.net/images/screenshots/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-bin.zip \
		crates.png:icons
DIST_SUBDIR=	java
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-bin.zip

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Pilot a small space ship

LICENSE=	GPLv2

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=	DATA

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

REPLACE_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

PORTDATA=	*
PORTDOCS=	AUTHORS README.txt
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

.include <bsd.port.options.mk>

post-patch-script:
	@${SED} ${REPLACE_LIST_TEMP} ${WRKSRC}/run.sh > ${WRKSRC}/run.sh.new

do-install:
# Executable
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh.new ${PREFIX}/bin/${PORTNAME}

# Data
.if ${PORT_OPTIONS:MDATA}
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data ghosts jar" ${DATADIR})
.  for d in hiscores.dat log4j.properties
	${INSTALL_DATA} ${WRKSRC}/${d} ${DATADIR}
.  endfor
.endif

# Pixmaps
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/crates.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
