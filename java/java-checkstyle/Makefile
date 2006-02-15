# Ports collection makefile for:    Java Checkstyle
# Date created:         2002/09/02
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	4.1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	java-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dave@glowacki.org
COMMENT=	Java style checker

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
ALL_TARGET=	build.bindist
USE_JIKES=	no

PLIST=	${WRKDIR}/PLIST

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_FILES=	bin/checkstyle %%JAVAJARDIR%%/${PORTNAME}.jar %%JAVAJARDIR%%/${PORTNAME}-optional.jar \
		%%DATADIR%%/examples/conf/sun_checks.xml
.if !defined(NOPORTDOCS)
BUILDDIR=	${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README LICENSE* RIGHTS* docs
.endif

SUB_FILES=	checkstyle.sh

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@${FIND} ${BUILDDIR}/contrib/ -type f -print | \
		${SED} "s,^${BUILDDIR}/contrib,${DATADIR:S,${PREFIX}/,,}," >> ${PLIST}
	@${FIND} ${BUILDDIR}/contrib/ -type d -print | ${SORT} -r | \
		${SED} -e "s,^${BUILDDIR}/contrib,@dirrm ${DATADIR:S,${PREFIX}/,,}," >> ${PLIST}

do-install: do-install-jar do-install-data do-install-apidocs \
		do-install-script

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${BUILDDIR}/${PORTNAME}-all-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${BUILDDIR}/${PORTNAME}-optional-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}-optional.jar

do-install-data:
	@${MKDIR} ${DATADIR}
	@${CP} -r ${BUILDDIR}/contrib/* ${DATADIR}
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sun_checks.xml ${DATADIR}/examples/conf/

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -r ${BUILDDIR}/${DOCFILE} ${DOCSDIR}/
.endfor
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

do-install-script:
	@${INSTALL_SCRIPT} ${WRKDIR}/checkstyle.sh ${PREFIX}/bin/checkstyle

.include <bsd.port.mk>
