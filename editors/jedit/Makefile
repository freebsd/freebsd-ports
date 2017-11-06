# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jedit
PORTVERSION=	5.4.0
PORTEPOCH=	1
CATEGORIES=	editors java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}install
EXTRACT_SUFX=	.jar

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Powerful programmer's text editor written in Java

LICENSE=	GPLv2

OPTIONS_DEFINE=	MACROS DOCS
MACROS_DESC=	Install default set of macros (highly recommended)

OPTIONS_DEFAULT=	MACROS
OPTIONS_SUB=	yes

USES=		cpe

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

post-extract:
	@(cd ${WRKDIR}/installer ; ${TAR} -xjf jedit-api.tar.bz2 ;\
		${TAR} -xjf jedit-macros.tar.bz2 ; \
		${TAR} -xjf jedit-program.tar.bz2)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/installer/${PORTNAME}.jar ${STAGEDIR}${DATADIR}/
.for dir in doc jars keymaps modes properties startup
	(cd ${WRKDIR}/installer ; ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}/)
.endfor
	(cd ${WRKDIR}/installer ; ${TAR} --exclude 'modes' --exclude 'keymaps' \
		-chf - macros | ${TAR}  -xf - -C ${STAGEDIR}${DATADIR}/)
	${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${STAGEDIR}${PREFIX}/bin/jedit
	${INSTALL_DATA} ${STAGEDIR}${DATADIR}/doc/jedit.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKDIR}/jedit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
