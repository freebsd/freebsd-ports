# New ports collection makefile for:	JRuby
# Date created:			20 September 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jruby
PORTVERSION=	0.5.3
CATEGORIES=	lang ruby java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An implementation of Ruby Interpreter in Pure Java

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

JRUBY_HOME?=	${PREFIX}/share/${PORTNAME}

PLIST_SUB=	JRUBY_HOME="${JRUBY_HOME:S,^${PREFIX}/,,}"

post-extract:
	${MV} ${WRKSRC}/README ${WRKSRC}/docs/
	${RM} ${WRKSRC}/lib/COPYING.LIB

post-patch:
	${REINPLACE_CMD} -e 's,!!JRUBY_HOME!!,${JRUBY_HOME},g' \
		${WRKSRC}/bin/jruby.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/jruby.sh ${PREFIX}/bin/jruby
	${MKDIR} ${JRUBY_HOME}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${JRUBY_HOME}/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
