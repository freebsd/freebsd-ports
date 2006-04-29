# New ports collection makefile for:   onis
# Date created:                                29 March 2003
# Whom:                                        koji@jet.es
#
# $FreeBSD$
#

PORTNAME=	onis
PORTVERSION=	0.8.2
CATEGORIES=	irc
MASTER_SITES=	http://verplant.org/onis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A script that converts IRC logfiles into an HTML statistics page

NO_BUILD=	YES
USE_PERL5=	YES

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=This port requires perl 5.6.x or later. Install lang/perl5 and try again.
.endif

do-install:
	@if [ ! -d ${DATADIR} ]; then \
		${MKDIR} ${DATADIR}; \
	fi
	${CP} -R ${WRKSRC}/* ${DATADIR}/

.include <bsd.port.post.mk>
