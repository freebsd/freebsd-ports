# New ports collection makefile for:	JRuby
# Date created:			20 September 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jruby
PORTVERSION=	0.3.1
CATEGORIES=	lang ruby java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION:S/./_/g}${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${JAVA}:${PORTSDIR}/java/javavmwrapper
#RUN_DEPENDS=	${JAVA}:${PORTSDIR}/java/linux-jdk13

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}

JAVA?=		${LOCALBASE}/bin/javavm

.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-src-${PORTVERSION:S/./_/g}${EXTRACT_SUFX}

FILES=		README README.test test.rb samples
.endif

post-extract:
	${FIND} ${WRKSRC} -name '*.swp' -delete

do-build:
	( \
	${ECHO} '#!/bin/sh'; \
	${ECHO} 'exec ${JAVA} -jar ${PREFIX}/share/java/classes/jruby.jar "$$@"'; \
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
	${ECHO} '@dirrm share/java/${PORTNAME}' >> ${TMPPLIST}
.endif
	${ECHO} '@unexec ${RMDIR} %D/share/java 2> /dev/null || true' >> ${TMPPLIST}

.include <bsd.port.mk>
