# New ports collection makefile for:	Scala
# Date created:			21 April 2009
# Whom:				Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	scala
PORTVERSION=	2.9.0.1
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/downloads/distrib/files/ \
		LOCAL/glarkin
EXTRACT_SUFX=	.tgz

MAINTAINER=	mitsururike@gmail.com
COMMENT=	The Scala Programming Language

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

MAN1=		fsc.1 sbaz.1 scala.1 scalac.1 scaladoc.1 scalap.1

SCALA_HOME?=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}
SCALA_SHRDIRS=	lib meta misc
SCALA_BINS=	fsc \
		sbaz \
		sbaz-setup \
		scala \
		scalac \
		scaladoc \
		scalap

PLIST_SUB+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   SCALA_HOME:    ${SCALA_HOME}"

post-patch:
.for f in ${SCALA_BINS}
	@${REINPLACE_CMD} 's|^#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${WRKSRC}/bin/${f}
.endfor

do-install:
	@${ECHO_MSG} ">> Installing Scala files..."
	@${INSTALL} -d ${SCALA_HOME}/bin
.for f in ${SCALA_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${SCALA_HOME}/bin/${f}
	${LN} -s ${SCALA_HOME}/${f} ${PREFIX}/bin/${f}
.endfor
.for d in ${SCALA_SHRDIRS}
	@cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} . ${SCALA_HOME}/${d}
.endfor
.for m in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${m} ${MANPREFIX}/man/man1/${m}
.endfor

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ">> Installing documentation files..."
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
