# ex:ts=8
# Ports collection makefile for:	batik
# Date created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	batik
PORTVERSION=	1.5.1
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SVG Toolkit

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_ZIP=	yes
USE_JAVA=	1.3+
NEED_JAVAC=	yes
WRKSRC=		${WRKDIR}/xml-${PORTNAME}
ANT?=		/usr/local/bin/ant
ANT_ALL_TARGET=	jars
BATIK_HOME=	${PREFIX}/batik

.if !defined(NOPORTDOCS)
ANT_ALL_TARGET+=	html
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_ALL_TARGET}

do-install:
	@${MKDIR} ${BATIK_HOME}
	@${CP} -R ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${BATIK_HOME}
	@${FIND} ${BATIK_HOME} -type f | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${BATIK_HOME} -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.post.mk>
