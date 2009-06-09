# New ports collection makefile for:    ripit
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $FreeBSD$
#

PORTNAME=	ripit
PORTVERSION=	3.7.0
CATEGORIES=	audio
MASTER_SITES=	http://www.suwald.com/ripit/

MAINTAINER=	oyvind@moll.no
COMMENT=	A command line audio CD ripper

# See pkg-message about other dependencies.
RUN_DEPENDS=	${SITE_PERL}/CDDB_get.pm:${PORTSDIR}/audio/p5-CDDB_get
RUN_DEPENDS+=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia

NO_BUILD=	yes
PLIST_FILES=	bin/ripit
MAN1=		ripit.1
PORTEXAMPLES=	config
USE_PERL5_RUN=	yes
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|#!/usr/bin/env perl|#!${PERL}|" ${WRKSRC}/ripit.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${PREFIX}/bin/ripit
	${INSTALL_MAN} ${WRKSRC}/ripit.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${EXAMPLESDIR}/config
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
