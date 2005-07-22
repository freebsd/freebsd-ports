# New ports collection makefile for:	cgiirc
# Date created:		2005-07-17
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	cgiirc
PORTVERSION=	0.5.7
CATEGORIES=	irc www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	cgiirc

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	IRC web gate written on perl

USE_PERL5=	yes
NO_BUILD=	yes

pre-install:
	@${MV} ${WRKSRC}/cgiirc.config ${WRKSRC}/cgiirc.config.sample 2>/dev/null || true

do-install:
	${MKDIR} ${PREFIX}/www/cgiirc
	${CP} -rp ${WRKSRC}/* ${PREFIX}/www/cgiirc
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/cgiirc
	@[ -f ${PREFIX}/www/cgiirc/cgiirc.config ] || \
	${CP} ${WRKSRC}/cgiirc.config.sample ${PREFIX}/www/cgiirc/cgiirc.config

.include <bsd.port.mk>
