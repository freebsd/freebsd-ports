# New ports collection makefile for:	JRuby
# Date created:			20 September 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jruby
PORTVERSION=	0.5.1
CATEGORIES=	lang ruby java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${BINDIST}
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	${BINDIST}

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${JAVA}:${PORTSDIR}/java/javavmwrapper
#RUN_DEPENDS=	${JAVA}:${PORTSDIR}/java/linux-jdk13

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}

JAVA?=		${LOCALBASE}/bin/javavm

BINDIST=	${PORTNAME}-${PORTVERSION:S/./_/g}${EXTRACT_SUFX}
SRCDIST=	${PORTNAME}-src-${PORTVERSION:S/./_/g}${EXTRACT_SUFX}

.if !defined(NOPORTDOCS)
DISTFILES+=	${SRCDIST}

FILES=		README samples src
.endif

post-extract:
.if !defined(NOPORTDOCS)
	${MKDIR} ${WRKSRC}/src
	cd ${WRKSRC}/src; ${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${SRCDIST}
.endif
	${FIND} ${WRKSRC} -name '*.swp' -delete

do-build:
	( \
	${ECHO_CMD} '#!/bin/sh'; \
	${ECHO_CMD} 'exec ${JAVA} -jar ${PREFIX}/share/java/classes/jruby.jar "$$@"'; \
	) > ${WRKSRC}/jruby

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jruby ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/java/classes
	${INSTALL_DATA} ${WRKSRC}/jruby.jar ${PREFIX}/share/java/classes/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/java/${PORTNAME}
	cd ${WRKSRC}; ${CP} -R ${FILES} ${PREFIX}/share/java/${PORTNAME}/
.endif

post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; find ${FILES} -type f | sort | ${SED} 's,^,share/java/${PORTNAME}/,' >> ${TMPPLIST}
	cd ${WRKSRC}; find ${FILES} -type d | sort -r | ${SED} 's,^,@dirrm share/java/${PORTNAME}/,' >> ${TMPPLIST}
	${ECHO_CMD} '@dirrm share/java/${PORTNAME}' >> ${TMPPLIST}
.endif
	${ECHO_CMD} '@unexec ${RMDIR} %D/share/java 2> /dev/null || true' >> ${TMPPLIST}

.include <bsd.port.mk>
