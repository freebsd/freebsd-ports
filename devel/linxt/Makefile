# New ports collection makefile for:	linxt
# Date created:		2007-05-05
# Whom:			Jason Bacon <bacon@smithers.neuro.mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	linxt
PORTVERSION=	0.1
CATEGORIES=	devel comms
MASTER_SITES=	SF \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Perl script for controlling Lego NXT brick

RUN_DEPENDS=	${SITE_PERL}/mach/Device/USB.pm:${PORTSDIR}/devel/p5-usb

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linxt ${PREFIX}/bin
	@${ECHO_CMD}
	@${CAT} pkg-message
	@${ECHO_CMD}

PLIST_FILES=	bin/linxt

.include <bsd.port.mk>
