# New ports collection makefile for:	subclipse
# Date created:				06 Mar 2005
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	subclipse
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://subclipse.tigris.org/files/documents/906/44501/
DISTNAME=	site-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A subversion plugin for the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_ZIP=	yes

ECLIPSE=	${PREFIX}/eclipse
SUBCLIPSE=	org.tigris.subversion.subclipse
SUBCLIPSEFILES=	features/${SUBCLIPSE}_${PORTVERSION} \
		features/${SUBCLIPSE}.graph.feature_1.0.1 \
		features/${SUBCLIPSE}.mylyn_2.0.4 \
		features/${SUBCLIPSE}.mylyn_3.0.0 \
		features/org.tigris.subversion.clientadapter.feature_1.5.2 \
		features/org.tigris.subversion.clientadapter.javahl.feature_1.5.4.1 \
		features/org.tigris.subversion.clientadapter.svnkit.feature_1.5.4 \
		features/com.sun.jna_3.0.9 \
		features/org.tmatesoft.svnkit_1.2.1.5297 \
		plugins/org.tigris.subversion.clientadapter_1.5.2 \
		plugins/org.tigris.subversion.clientadapter.javahl_1.5.4.1 \
		plugins/org.tigris.subversion.clientadapter.svnkit_1.5.4 \
		plugins/${SUBCLIPSE}.core_${PORTVERSION} \
		plugins/${SUBCLIPSE}.doc_1.3.0 \
		plugins/${SUBCLIPSE}.graph_1.0.1 \
		plugins/${SUBCLIPSE}.mylyn_2.0.4 \
		plugins/${SUBCLIPSE}.mylyn_3.0.0 \
		plugins/${SUBCLIPSE}.ui_${PORTVERSION} \
		plugins/com.sun.jna_3.0.9 \
		plugins/org.tmatesoft.svnkit_1.2.1.5297

.include <bsd.port.pre.mk>

post-extract:
.for f in ${SUBCLIPSEFILES}
	cd ${WRKSRC} \
	  && ${MKDIR} ${f} \
	  && ${UNZIP_CMD} ${f}.jar -d ${f}
.endfor

do-install:
.for f in ${SUBCLIPSEFILES}
	@cd ${WRKSRC} \
	  && ${MKDIR} ${ECLIPSE}/${f} \
	  && ${FIND} ${f} -type d -exec ${MKDIR} ${ECLIPSE}/{} \; \
	  && ${FIND} ${f} -type f -exec ${INSTALL_DATA} {} ${ECLIPSE}/{} \;
.endfor

post-install:
.for f in ${SUBCLIPSEFILES}
	@${FIND} ${WRKSRC}/${f} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${f} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${ECLIPSE:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
