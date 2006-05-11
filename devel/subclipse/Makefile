# New ports collection makefile for:	subclipse
# Date created:				06 Mar 2005
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	subclipse
PORTVERSION=	1.0.1
CATEGORIES=	devel java
MASTER_SITES=	http://subclipse.tigris.org/files/documents/906/31284
DISTNAME=	site-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A subversion plugin for the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse
FETCH_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

CONFLICTS=	phpeclipse-[0-9]*

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_ZIP=	yes

ECLIPSE=	${PREFIX}/eclipse
SUBCLIPSE=	org.tigris.subversion.subclipse
SUBCLIPSEFILES=	features/${SUBCLIPSE}_${PORTVERSION} \
		plugins/${SUBCLIPSE}.core_${PORTVERSION} \
		plugins/${SUBCLIPSE}.ui_${PORTVERSION} \
		plugins/${SUBCLIPSE}_${PORTVERSION}

WGET?=		${LOCALBASE}/bin/wget

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.zip)
	${WGET} -P${DISTDIR}/${DIST_SUBDIR} ${MASTER_SITES}/${DISTNAME}.zip
.endif

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
