# $FreeBSD$

PORTNAME=	openmap
PORTVERSION=	4.6.4
PORTREVISION=	1
CATEGORIES=	astro java devel graphics geography
MASTER_SITES=	http://openmap.bbn.com/src/

MAINTAINER=	des@FreeBSD.org
COMMENT=	Java toolkit for manipulating and displaying geographic data

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.6+

PKGMESSAGE=	${WRKSRC}/LICENSE

USE_ANT=	yes
MAKE_ARGS+=	-Dopenmap.home=${WRKSRC} \
		-Didl2java.compiler=${JAVA_HOME}/bin/idlj

SUB_FILES=	openmap.sh

OPTIONS_DEFINE=	DOCS

do-configure:
	(cd ${WRKSRC} && ${FIND} . -type f -print0 | ${XARGS} -0 \
	    ${REINPLACE_CMD} -e 's,/usr/local/openmap,${DATADIR},g')
	(cd ${WRKSRC} && ${FIND} . -type f -name \*.bak -delete)

do-install:
	(cd ${WRKSRC}/lib && \
	    ${INSTALL_DATA} *.jar ${STAGEDIR}${JAVAJARDIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/share && ${FIND} . -type f -print | \
	    ${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR})
	${FIND} ${STAGEDIR}${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0755
	${FIND} ${STAGEDIR}${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0644
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/openmap.sh ${STAGEDIR}${PREFIX}/bin/openmap
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} \
	    AUTHORS LICENSE README ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${FIND} . -type f -print | \
	    ${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR})
	${FIND} ${STAGEDIR}${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0755
	${FIND} ${STAGEDIR}${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0644

.include <bsd.port.mk>
