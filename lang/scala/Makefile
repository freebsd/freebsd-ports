# Created by: Mitsuru YOSHIDA <mitsuru@riken.jp>
# $FreeBSD$

PORTNAME=	scala
PORTVERSION=	2.10.0
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/downloads/distrib/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mitsururike@gmail.com
COMMENT=	The Scala Programming Language

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

SCALA_HOME=	${DATADIR}
SCALA_SHRDIRS=	lib misc src
SCALA_DOCDIRS=	tools
SCALA_BINS=	fsc \
		scala \
		scalac \
		scaladoc \
		scalap

MAN1=		${SCALA_BINS:S,$,.1,}

PLIST_FILES=	${SCALA_BINS:S,^,bin/,}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   SCALA_HOME:    ${SCALA_HOME}"

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${SCALA_HOME}/bin
.for f in ${SCALA_BINS}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${SCALA_HOME}/bin/${f}
	@${LN} -s ${SCALA_HOME}/bin/${f} ${PREFIX}/bin/${f}
.endfor
.for d in ${SCALA_SHRDIRS}
	@cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} . ${SCALA_HOME}/${d}
.endfor
.for m in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${m} ${MANPREFIX}/man/man1/${m}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for d in ${SCALA_DOCDIRS}
	@cd ${WRKSRC}/doc/${d} && ${COPYTREE_SHARE} . ${DOCSDIR}/${d}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
