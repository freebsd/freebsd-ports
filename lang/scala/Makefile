# New ports collection makefile for:	Scala
# Date created:			21 April 2009
# Whom:				Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	scala
PORTVERSION=	2.7.4
DISTVERSIONSUFFIX=	.final
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/downloads/distrib/files/ \
		LOCAL/glarkin
EXTRACT_SUFX=	.tgz

MAINTAINER=	mitsuru@riken.jp
COMMENT=	The Scala Programming Language

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

MAN1=		fsc.1 sbaz.1 scala.1 scalac.1 scaladoc.1

SCALA_HOME?=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}
SCALA_SHRDIRS=	lib meta misc

PLIST_SUB+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   SCALA_HOME:    ${SCALA_HOME}"

do-install:
	@${ECHO_MSG} ">> Installing Scala files..."
	@${INSTALL} -d ${SCALA_HOME}/bin
	@cd ${WRKSRC}/bin \
	  && ${FIND} . -perm 755 -type f -exec ${INSTALL_SCRIPT} {} \
	  ${SCALA_HOME}/bin/{} \;
.for target in ${SCALA_SHRDIRS}
	@cd ${WRKSRC}/${target} \
	  && ${FIND} . -type d -exec ${INSTALL} -d ${SCALA_HOME}/${target}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} \
	  ${SCALA_HOME}/${target}/{} \;
.endfor
	@cd ${WRKSRC}/man/man1 \
	  && ${FIND} . -type f -exec ${INSTALL_MAN} {} \
	  ${MANPREFIX}/man/man1/{} \;
	@${ECHO_MSG} ">> Installing symlinks in ${PREFIX}/bin..."
	@cd ${SCALA_HOME}/bin \
	  && ${FIND} . -type f -exec ${LN} -s ${SCALA_HOME}/bin/{} \
	  ${PREFIX}/bin/{} \;

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ">> Installing documentation files..."
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
