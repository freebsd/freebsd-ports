# Ports collection makefile for:    Java Checkstyle
# Date created:         2002/09/02
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	java-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	dglo@icecube.wisc.edu
COMMENT=	Java style checker

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
ALL_TARGET=	build.bindist
USE_JIKES=	no

PLIST=	${WRKDIR}/PLIST

STYLEDIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_FILES=	bin/checkstyle %%JAVAJARDIR%%/${PORTNAME}.jar %%JAVAJARDIR%%/${PORTNAME}-optional.jar \
		${STYLEDIR:S,${PREFIX}/,,}/examples/conf/sun_checks.xml
.if !defined(NOPORTDOCS)
BUILDDIR=	${WRKSRC}/target/dist/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README LICENSE* TODO RIGHTS* docs
.endif

do-configure:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g ; s,%%JAVAJARDIR%%,${JAVAJARDIR},g' \
		${FILESDIR}/checkstyle.sh > ${WRKSRC}/checkstyle

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@${FIND} ${BUILDDIR}/contrib/ -type f -print | \
		${SED} "s,^${BUILDDIR}/contrib,${STYLEDIR:S,${PREFIX}/,,}," >> ${PLIST}
	@${FIND} ${BUILDDIR}/contrib/ -type d -print | ${SORT} -r | \
		${SED} -e "s,^${BUILDDIR}/contrib,@dirrm ${STYLEDIR:S,${PREFIX}/,,}," >> ${PLIST}

do-install: do-install-jar do-install-data do-install-apidocs \
		do-install-script

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${BUILDDIR}/${PORTNAME}-all-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${BUILDDIR}/${PORTNAME}-optional-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}-optional.jar

do-install-data:
	@${MKDIR} ${STYLEDIR}
	@${CP} -r ${BUILDDIR}/contrib/* ${STYLEDIR}
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${STYLEDIR}
	@${INSTALL_DATA} ${WRKSRC}/sun_checks.xml ${STYLEDIR}/examples/conf/

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -r ${BUILDDIR}/${DOCFILE} ${DOCSDIR}/
.endfor
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

do-install-script:
	@${INSTALL_SCRIPT} ${WRKSRC}/checkstyle ${PREFIX}/bin/checkstyle

.include <bsd.port.mk>
