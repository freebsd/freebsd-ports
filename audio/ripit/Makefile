# New ports collection makefile for:    ripit
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $FreeBSD$
#

PORTNAME=	ripit
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.initio.no/~oyvindmo/distfiles/

MAINTAINER=	oyvindmo@initio.no

# See pkg-message about other dependencies.
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/CDDB_get.pm:${PORTSDIR}/audio/p5-CDDB_get
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
RUN_DEPENDS+=	dagrab:${PORTSDIR}/audio/dagrab

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@ ${PERL} -pi -ne "s|#!/usr/bin/perl|#!${PERL}|" ${WRKSRC}/ripit.pl

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${PREFIX}/bin

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
