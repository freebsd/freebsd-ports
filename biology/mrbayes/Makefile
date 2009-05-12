# New ports collection makefile for:	mrbayes
# Date created:				11 December 2007
# Whom:					mzaki@biol.s.u-tokyo.ac.jp
#
# $FreeBSD$
#

PORTNAME=	mrbayes
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	SF

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Bayesian inference of phylogeny

USE_GMAKE=	yes

LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline

PLIST_FILES=	bin/mb

PORTEXAMPLES=	adh.nex anolis.nex avian_ovomucoids.nex bglobin.nex \
		cynmix.nex kim.nex primates.nex replicase.nex

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mb ${PREFIX}/bin/
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
