# New ports collection makefile for:    ripit
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $FreeBSD$
#

PORTNAME=	ripit
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.initio.no/~oyvindmo/distfiles/

MAINTAINER=	oyvindmo@initio.no
COMMENT=	A perl-script frontend for encoding audio CDs to MP3 files

# See pkg-message about other dependencies.
RUN_DEPENDS=	${SITE_PERL}/CDDB_get.pm:${PORTSDIR}/audio/p5-CDDB_get
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
RUN_DEPENDS+=	dagrab:${PORTSDIR}/audio/dagrab

NO_BUILD=	yes
PLIST_FILES=	bin/ripit.pl
USE_PERL5=	yes

post-patch:
	@ ${PERL} -pi -ne "s|#!/usr/bin/perl|#!${PERL}|" ${WRKSRC}/ripit.pl

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${PREFIX}/bin

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
