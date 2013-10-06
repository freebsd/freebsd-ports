# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jedit
PORTVERSION=	5.1.0
PORTEPOCH=	1
CATEGORIES=	editors java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}install
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Powerful programmer\'s text editor written in Java

LICENSE=	GPLv2

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

OPTIONS_DEFINE=	MACROS DOCS
MACROS_DESC=	Install default set of macros (highly recommended)

OPTIONS_DEFAULT=	MACROS
OPTIONS_SUB=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_XORG=	x11
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DOCSDIR=	${DATADIR}/doc
PORTDOCS=	*
SUB_FILES=	jedit.sh

DESKTOP_ENTRIES="jEdit" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Development;" false

do-install:
	@${PRINTF} "${STAGEDIR}${DATADIR}\n${WRKDIR}\n${STAGEDIR}${PREFIX}/man/man1\nY\nY\nY" | \
		${SETENV} CLASSPATH=${DISTDIR}/${DISTNAME}.jar \
		${JAVA} installer.Install text
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${STAGEDIR}${PREFIX}/bin/jedit
	@${INSTALL_DATA} ${STAGEDIR}${DATADIR}/doc/jedit.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
