# New ports collection makefile for: tircd
# Date created:		6th March 2010
# Whom:			Gavin Atkinson <gavin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tircd
PORTVERSION=	0.10
CATEGORIES=	irc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	IRC proxy to Twitter

RUN_DEPENDS=	p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Time-Local>=0:${PORTSDIR}/devel/p5-Time-Local \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-Net-Twitter-Lite>=0:${PORTSDIR}/net/p5-Net-Twitter-Lite \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Filter-IRCD>=0:${PORTSDIR}/irc/p5-POE-Filter-IRCD

WRKSRC=		${WRKDIR}/tircd

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		tircd.1
USE_RC_SUBR=	tircd

post-patch:
	${REINPLACE_CMD} -e '1s,^#!/usr/bin/perl,#!${PREFIX}/bin/perl,' \
			 -e 's,/etc/tircd.cfg,${PREFIX}/etc/tircd.cfg,g' \
			 ${WRKSRC}/tircd.pl ${WRKSRC}/tircd.pod
	pod2man ${WRKSRC}/tircd.pod > ${WRKSRC}/tircd.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tircd.pl ${PREFIX}/bin/tircd.pl
	${INSTALL_MAN} ${WRKSRC}/tircd.1 ${MAN1PREFIX}/man/man1/tircd.1
	${INSTALL_DATA} ${WRKSRC}/tircd.cfg.example ${PREFIX}/etc/tircd.cfg.example
	@if [ ! -f ${PREFIX}/etc/tircd.cfg ]; then \
		${CP} -p ${PREFIX}/etc/tircd.cfg.example ${PREFIX}/etc/tircd.cfg ; \
	fi

.include <bsd.port.mk>
