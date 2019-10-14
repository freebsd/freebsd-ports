# Created by: Mitsuru YOSHIDA <mitsuru@riken.jp>
# $FreeBSD$

PORTNAME=	scala
PORTVERSION=	2.13.1
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/files/archive/

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Scala Programming Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		tar:tgz

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+

SCALA_HOME=	${DATADIR}
SCALA_SHRDIRS=	lib
SCALA_DOCDIRS=	tools
SCALA_BINS=	fsc \
		scala \
		scalac \
		scaladoc \
		scalap

SCALA_MANS=	${SCALA_BINS:S,$,.1,}
PLIST_FILES=	${SCALA_BINS:S,^,bin/,} \
	man/man1/fsc.1.gz \
	man/man1/scala.1.gz \
	man/man1/scalac.1.gz \
	man/man1/scaladoc.1.gz \
	man/man1/scalap.1.gz

PORTDATA=	*
PORTDOCS=	*

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   SCALA_HOME:    ${SCALA_HOME}"

do-install:
	@${MKDIR} ${STAGEDIR}${SCALA_HOME}/bin
.for f in ${SCALA_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${SCALA_HOME}/bin/${f}
	${LN} -s ${SCALA_HOME}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.for d in ${SCALA_SHRDIRS}
	(cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${SCALA_HOME}/${d})
.endfor
.for m in ${SCALA_MANS}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${m} ${STAGEDIR}${MANPREFIX}/man/man1/${m}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${SCALA_DOCDIRS}
	(cd ${WRKSRC}/doc/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${d})
.endfor

.include <bsd.port.mk>
