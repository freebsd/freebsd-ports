# New ports collection makefile for:	jakarta-ant
# Date created:		21 February 2001
# Whom:			ernst@jollem.com
#
# $FreeBSD$
#

PORTNAME=	jakarta-ant
PORTVERSION=	1.4.1
CATEGORIES=	devel java
MASTER_SITES=	http://jakarta.apache.org/builds/${PORTNAME}/release/v${PORTVERSION}/bin/ \
		http://metaverse.euronet.nl/~ernst/
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX} \
		${DISTNAME}-optional.jar
DIST_SUBDIR=	jakarta
EXTRACT_ONLY=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/share/java/classes/crimson.jar:${PORTSDIR}/textproc/crimson

JAVAVM?=	${LOCALBASE}/bin/javavm
FIND?=		/usr/bin/find

NO_BUILD=	YES
ANT_SUBDIR=	${DISTNAME}
PORTDESTDIR=	${PREFIX}/share/java/${ANT_SUBDIR}
PLIST_SUB+=	T=${PORTDESTDIR:S/^${PREFIX}\///}

READMES=	LICENSE README WHATSNEW
SCRIPTS=	bin/ant bin/antRun bin/runant.pl

DATADIRS=	lib
.if !defined(NOPORTDOCS)
DATADIRS+=	docs
.endif

post-patch:
	@${PERL} -pi -e 's,JAVACMD=java,JAVACMD=javavm,g' ${WRKSRC}/bin/ant

do-install:
	${MKDIR} ${PORTDESTDIR}/bin ${PORTDESTDIR}/lib
	cd ${INSTALL_WRKSRC}; \
		${INSTALL_SCRIPT} ${SCRIPTS} ${PORTDESTDIR}/bin; \
		${INSTALL_DATA} ${READMES} ${PORTDESTDIR};
	${LN} -sf ${PORTDESTDIR}/bin/ant ${PREFIX}/bin
.if defined(DATADIRS)
.for DIR in ${DATADIRS}
	cd ${INSTALL_WRKSRC}; \
		${FIND} ${DIR} -type d -exec ${MKDIR} ${PORTDESTDIR}/\{} \; ;\
		${FIND} ${DIR} -type f -exec ${INSTALL_DATA} \{} ${PORTDESTDIR}/\{} \;
.endfor
.endif
	${RM} -f ${PORTDESTDIR}/lib/parser.jar
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME}-optional.jar ${PORTDESTDIR}/lib/optional.jar
	${LN} -sf ${LOCALBASE}/share/java/classes/jaxp.jar ${PORTDESTDIR}/lib
	${LN} -sf ${LOCALBASE}/share/java/classes/crimson.jar ${PORTDESTDIR}/lib

.include <bsd.port.mk>
