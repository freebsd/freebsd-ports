# New ports collection makefile for:	freemind
# Date created:	22 september 2004
# Whom:		cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	freemind
PORTVERSION=	0.8.0
PORTEPOCH=	1
CATEGORIES=	deskutils editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freemind
DISTNAME=	${PORTNAME}-bin-max-${PORTVERSION:S/./_/g}

MAINTAINER=	cartola@openit.com.br
COMMENT=	Free mind-mapping software written in Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

.if !exists(/usr/bin/unzip)
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif
.if !exists(/usr/bin/zip)
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
.endif

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DATAFILES=	accessories doc lib license patterns.xml plugins user.properties

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
ZIP_CMD=	zip

SUB_FILES=	freemind.sh

do-build:
	(cd ${WRKSRC}; \
	${UNZIP_CMD} lib/freemind.jar freemind.properties; \
	${REINPLACE_CMD} -e '/^keystroke_node_increase_font_size/ s/PLUS/EQUALS/;/^keystroke_branch_increase_font_size/ s/PLUS/EQUALS/;s|./doc/freemind.mm|file:${DATADIR}/doc/freemind.mm|' freemind.properties; \
	${ZIP_CMD} -u lib/freemind.jar freemind.properties)

do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/freemind.sh ${PREFIX}/bin/freemind

.include <bsd.port.mk>
