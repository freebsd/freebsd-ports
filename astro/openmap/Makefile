# $FreeBSD$

PORTNAME=	openmap
PORTVERSION=	4.6.4
CATEGORIES=	astro java devel graphics geography
MASTER_SITES=	http://openmap.bbn.com/src/

MAINTAINER=	des@FreeBSD.org
COMMENT=	Java toolkit for manipulating and displaying geographic data

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.6+

PKGMESSAGE=	${WRKSRC}/LICENSE

NO_STAGE=	yes
USE_ANT=	yes
MAKE_ARGS+=	-Dopenmap.home=${WRKSRC} \
		-Didl2java.compiler=${JAVA_HOME}/bin/idlj

SUB_FILES=	openmap.sh

.include <bsd.port.options.mk>

do-configure:
	(cd ${WRKSRC} && ${FIND} . -type f -print0 | ${XARGS} -0 \
	    ${REINPLACE_CMD} -e 's,/usr/local/openmap,${DATADIR},g')
	(cd ${WRKSRC} && ${FIND} . -type f -name \*.bak -delete)

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
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${FIND} . -type f -print | \
	    ${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${DOCSDIR})
	${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0555
	${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0444
.endif

.include <bsd.port.mk>
