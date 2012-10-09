# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-ide
DISTVERSION=	2.1.0m2
CATEGORIES=	devel java
MASTER_SITES=	http://download.scala-ide.org/releases-29/milestone/ \
		http://download.scala-ide.org/ecosystem/dev-milestone-2.9/site/features/:feature \
		http://download.scala-ide.org/ecosystem/dev-milestone-2.9/site/plugins/:plugin
DISTFILES=	org.scala-ide.sdt.update-site${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	org.scala-ide.sdt.update-site${EXTRACT_SUFX}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Scala plugin for the Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

OPTIONS_DEFINE=	SCALATEST WORKSHEET
OPTIONS_DEFAULT=SCALATEST WORKSHEET

SCALATEST_DESC=	Install ScalaTest
WORKSHEET_DESC=	Install Scala Worksheet

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/site

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCALATEST}
FEATURES+=	org.scala-ide.sdt.scalatest.feature_0.9.3.jar \
		org.scala-ide.sdt.scalatest.source.feature_0.9.3.jar
PLUGINS+=	org.scala-ide.sdt.scalatest.source_0.9.3.jar \
		org.scala-ide.sdt.scalatest_0.9.3.jar
.endif

.if ${PORT_OPTIONS:MWORKSHEET}
FEATURES+=	org.scalaide.worksheet.feature_0.1.1.v-2_09-201209171937-dc86a45.jar \
		org.scalaide.worksheet.source.feature_0.1.1.v-2_09-201209171937-dc86a45.jar
PLUGINS+=	org.scalaide.worksheet.source_0.1.1.v-2_09-201209171937-dc86a45.jar \
		org.scalaide.worksheet_0.1.1.v-2_09-201209171937-dc86a45.jar
.endif

.if ${PORT_OPTIONS:MSCALATEST} || ${PORT_OPTIONS:MWORKSHEET}
DISTFILES+=	${FEATURES:S/$/:feature/} ${PLUGINS:S/$/:plugin/}

post-extract:
.for f in ${FEATURES}
	@${CP} ${_DISTDIR}/${f} ${WRKSRC}/features/
.endfor
.for f in ${PLUGINS}
	@${CP} ${_DISTDIR}/${f} ${WRKSRC}/plugins/
.endfor
.endif

.include "${.CURDIR}/../../java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
