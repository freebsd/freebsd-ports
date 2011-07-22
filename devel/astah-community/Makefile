# New ports collection makefile for:	jude_take
# Date created:				19 April 2004
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	astah
PORTVERSION=	6.4.1
CATEGORIES=	devel java
MASTER_SITES=	#
PKGNAMESUFFIX=	-community
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION:S!.!_!g}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A Java/UML Object-Oriented Design Tool

USE_ZIP=	yes

.include <bsd.port.pre.mk>

JAVA_VERSION=	1.6+

USE_JAVA=	yes
JAVA_OS=	linux
NO_BUILD=	yes

RESTRICTED=	See http://astah.net/faq/community/enduser-license-agreement
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX:S!-!_!}
REINPLACE_ARGS=	-i ""

.if !exists(${DISTDIR}/${DISTFILES})
DOWNLOAD_URL=	http://members.change-vision.com/files/${PORTNAME}${PKGNAMESUFFIX:S!-!_!}/${PORTVERSION:S!.!_!}/${DISTFILES}
IGNORE=		needs you to fetch manually the distribution file\
		from ${DOWNLOAD_URL}, \
		then place it in ${DISTDIR} and run make again
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

PLIST_FILES=	bin/astah
.if !defined(NOPORTDATA)
PORTDATA=	astah-community.jar astah-api.jar astah-gui_en.properties_org \
		astah.ico astah-doc.ico Welcome.asta Welcome_ja.asta \
		lib template
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	ReleaseNote-e.html ReleaseNote.html \
		API_sample_program_license_agreement-e.txt \
		API_sample_program_license_agreement.txt
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	astah-key.properties_org
.endif

post-patch:
	${REINPLACE_CMD} -e "s!%%JAVA_HOME%%!${JAVA_HOME}!g; \
	                     s!%%DATADIR%%!${DATADIR}!" ${WRKSRC}/astah
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} 's/png\\/png\//' ${WRKSRC}/api/*/doc/astahAPI_reference.html
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/astah ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${DATADIR})
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/api
	(cd ${WRKSRC}/api && ${COPYTREE_SHARE} \* ${DOCSDIR}/api)
	@ cd ${PREFIX} && ${FIND} share/doc/${PORTNAME}${PKGNAMESUFFIX}/api -type f -print | \
		${SORT} -r >> ${TMPPLIST}
	@ cd ${PREFIX} && ${FIND} share/doc/${PORTNAME}${PKGNAMESUFFIX}/api -type d -print | \
		${SORT} -r |  ${SED} -e 's#^#@dirrm #' >> ${TMPPLIST}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
