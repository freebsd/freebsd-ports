# New ports collection makefile for:	subclipse
# Date created:				06 Mar 2005
# Whom:					tux@pinguru.net
#
# $FreeBSD$
#

PORTNAME=	subclipse
PORTVERSION=	0.9.36
CATEGORIES=	devel java
MASTER_SITES=	http://subclipse.tigris.org/files/documents/906/27309/
DISTNAME=	site.${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	tux@pinguru.net
COMMENT=	A subversion plugin for the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

CONFLICTS=	phpeclipse-[0-9]*

WRKSRC=		${WRKDIR}/update
NO_BUILD=	yes
USE_ZIP=	yes

ECLIPSE=	${PREFIX}/eclipse
SUBCLIPSE=	org.tigris.subversion.subclipse
SUBCLIPSEFILES=	features/${SUBCLIPSE}_${PORTVERSION} \
		plugins/${SUBCLIPSE}.core_${PORTVERSION} \
		plugins/${SUBCLIPSE}.ui_${PORTVERSION} \
		plugins/${SUBCLIPSE}_${PORTVERSION}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.zip)
IGNORE=		Due to the behaviour of the webserver subclipse is hosted on, you have to download the file yourself as ${MASTER_SITES}/${DISTNAME}.zip and place it in ${DISTDIR}/${DIST_SUBDIR}
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
