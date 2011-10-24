# New ports collection makefile for:	opengrok
# Date created:		10/13/2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	opengrok
PORTVERSION=	0.7
CATEGORIES=	devel java
MASTER_SITES=	http://opensolaris.org/os/project/opengrok/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and powerful code search and cross-reference egine

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
SUB_FILES=	opengrok
SUB_LIST+=	LIBFILES="${LIBFILES:S,^,${DATADIR}/,}" \
		JARFILE="${JARFILE}"

OPTIONS=	TOMCAT6		"Use Jakarta Tomcat 6"		on	\
		TOMCAT55	"Use Jakarta Tomcat 5.5"	off	\
		RESIN3		"Use Resin 3"			off

.include <bsd.port.pre.mk>

JARFILE=	${DATADIR}/opengrok.jar
WARFILE=	source.war
DOCS=		CHANGES.txt EXAMPLE.txt LICENSE.txt
LIBFILES=	ant.jar bcel-5.1.jar jakarta-oro-2.0.8.jar \
		jmxremote_optional.jar lucene-core-2.2.0.jar \
		lucene-spellchecker-2.2.0.jar org.apache.commons.jrcs.diff.jar \
		org.apache.commons.jrcs.rcs.jar servlet-api.jar \
		swing-layout-0.9.jar
WEBAPP_DIRS=	#empty

.if defined(WITH_TOMCAT55)
WEBAPP_DIRS+=	tomcat5.5
RUN_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
.endif

.if defined(WITH_TOMCAT6)
WEBAPP_DIRS+=	apache-tomcat-6.0
RUN_DEPENDS+=	${LOCALBASE}/apache-tomcat-6.0/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if defined(WITH_RESIN3)
WEBAPP_DIRS+=	resin3
RUN_DEPENDS+=	${LOCALBASE}/resin3/lib/resin.jar:${PORTSDIR}/www/resin3
.endif

do-install:
.if ${PREFIX}!=${LOCALBASE}
	@${ECHO_CMD} "Warning: you changed prefix to ${PREFIX}"
	@${ECHO_CMD} "Default installation will not work if you installed"
	@${ECHO_CMD} "application server in different prefix"
.endif
.for DIR in ${WEBAPP_DIRS}
	@${ECHO_CMD} "${DIR}/webapps/${WARFILE}" >> ${TMPPLIST}
	${MKDIR} ${PREFIX}/${DIR}/webapps
	@${ECHO_CMD} "@unexec rmdir %D/${DIR}/webapps 2>/dev/null || true" >> ${TMPPLIST}
	${INSTALL_DATA} ${WRKSRC}/${WARFILE} ${PREFIX}/${DIR}/webapps
.endfor
	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${LIBFILES:S,^,${WRKSRC}/lib/,} ${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/opengrok.jar ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/opengrok ${PREFIX}/bin

.include <bsd.port.post.mk>
