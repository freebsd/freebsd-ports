# Created by: Gavin Atkinson <gavin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tircd
PORTVERSION=	0.30
CATEGORIES=	irc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	IRC proxy to Twitter

RUN_DEPENDS=	p5-JSON-Any>=0:converters/p5-JSON-Any \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Time-Local>=0:devel/p5-Time-Local \
		p5-Storable>=0:devel/p5-Storable \
		p5-Net-Twitter-Lite>=0:net/p5-Net-Twitter-Lite \
		p5-POE>=0:devel/p5-POE \
		p5-POE-Filter-IRCD>=0:irc/p5-POE-Filter-IRCD

USES=		perl5 tar:tgz
USE_PERL5=	patch build run
NO_BUILD=	yes

USE_RC_SUBR=	tircd

post-patch:
	${REINPLACE_CMD} -e '1s,^#!/usr/bin/perl,#!${PREFIX}/bin/perl,' \
			 -e 's,/etc/tircd.cfg,${PREFIX}/etc/tircd.cfg,g' \
			 ${WRKSRC}/tircd.pl ${WRKSRC}/tircd.pod
	# pod2man needs perl
	pod2man ${WRKSRC}/tircd.pod > ${WRKSRC}/tircd.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tircd.pl ${STAGEDIR}${PREFIX}/bin/tircd.pl
	${INSTALL_MAN} ${WRKSRC}/tircd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/tircd.1
	${INSTALL_DATA} ${WRKSRC}/tircd.cfg.example ${STAGEDIR}${PREFIX}/etc/tircd.cfg.sample

.include <bsd.port.mk>
