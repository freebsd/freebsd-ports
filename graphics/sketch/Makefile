# New ports collection makefile for:	sketch
# Date created:		09 January 2008
# Whom:			Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sketch
PORTVERSION=	0.2.27
CATEGORIES=	graphics
MASTER_SITES=	http://www.frontiernet.net/~eugene.ressler/
EXTRACT_SUFX=	.tgz

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A 3D Scene Description Translator

USE_GMAKE=	yes
USE_PERL5_BUILD= yes

.if !defined(NOPORTDOCS)
PORTDOCS=	manual.html manual.pdf manual
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	2tori.sk buggy.sk bunny.sk cone.sk hand.sk test.sk
.endif

.include <bsd.port.pre.mk>

do-configure:

do-build:
	cd ${WRKSRC} && ${GMAKE} CFLAGS="${CFLAGS}" -f makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sketch ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.html ${WRKSRC}/Doc/manual.pdf ${DOCSDIR}
	cd ${WRKSRC}/Doc && ${FIND} manual -type f | ${CPIO} -dumpv ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/Data && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
