# New ports collection makefile for:	openmap
# Date created:				2005-07-30
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	openmap
PORTVERSION=	4.6.2
CATEGORIES=	astro java devel graphics
MASTER_SITES=	http://openmap.bbn.com/src/

MAINTAINER=	des@FreeBSD.org
COMMENT=	Java toolkit for manipulating and displaying geographic data

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant
RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	1.4+
USE_REINPLACE=	YES

PKGMESSAGE=	${WRKSRC}/LICENSE

ANT_PROPERTIES=	openmap.home=${WRKSRC} \
		idl2java.compiler=${JAVA_HOME}/bin/idlj
ANT_CMD=	${LOCALBASE}/bin/ant ${ANT_PROPERTIES:C/^/-D/}

do-configure:
	(cd ${WRKSRC} && ${FIND} . -type f -print0 | ${XARGS} -0 \
	    ${REINPLACE_CMD} -e 's,/usr/local/openmap,${DATADIR},g')
	(cd ${WRKSRC} && ${FIND} . -type f -name \*.bak -delete)
	${SED} \
	    -e 's,%%CLASSPATH%%,${LOCALBASE}/bin/classpath,' \
	    -e 's,%%JAVAVM%%,${LOCALBASE}/bin/java,' \
	    -e 's,%%DATADIR%%,${DATADIR},' \
	    <${FILESDIR}/openmap.sh >${WRKDIR}/openmap.sh

do-build:
	(cd ${WRKSRC} && ${ANT_CMD})

do-install:
	(cd ${WRKSRC}/lib && \
	    ${INSTALL_DATA} -o ${SHAREOWN} -g ${SHAREGRP} *.jar ${JAVAJARDIR})
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/share && ${FIND} . -type f -print | \
	    ${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${DATADIR})
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0555
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0444
	${INSTALL_SCRIPT} -o ${BINOWN} -g ${BINGRP} \
	    ${WRKDIR}/openmap.sh ${PREFIX}/bin/openmap
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} -o ${SHAREOWN} -g ${SHAREGRP} \
	    AUTHORS LICENSE README ${DOCSDIR})
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc && ${FIND} . -type f -print | \
	    ${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
	${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0555
	${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0444
.endif

.include <bsd.port.mk>
