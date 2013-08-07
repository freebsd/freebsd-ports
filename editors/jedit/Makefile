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

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Powerful programmer\'s text editor written in Java

LICENSE=	GPLv2

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

OPTIONS_DEFINE=	MACROS DOCS
MACROS_DESC=	Install default set of macros (highly recommended)

OPTIONS_DEFAULT=	MACROS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCS=y
.else
DOCS=n
.endif

.if ${PORT_OPTIONS:MMACROS}
MACROS=y
.else
MACROS=n
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_XORG=	x11
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jedit.sh

DESKTOP_ENTRIES="jEdit" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Development;" false

MAN1=		jedit.1
# The complete PLIST is generated in post-install
PLIST_FILES=	bin/jedit share/pixmaps/${PORTNAME}.png

do-install:
	@${PRINTF} "${DATADIR}\n${WRKDIR}\n${PREFIX}/man/man1\nY\n${MACROS}\n${DOCS}" | \
		${SETENV} CLASSPATH=${DISTDIR}/${DISTNAME}.jar \
		${JAVA} installer.Install text
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${PREFIX}/bin/jedit

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${INSTALL_DATA} ${DATADIR}/doc/jedit.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
