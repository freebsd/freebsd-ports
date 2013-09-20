# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	IO-All-LWP
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	IO::All interface to LWP

RUN_DEPENDS=	p5-IO-All>=0.30:${PORTSDIR}/devel/p5-IO-All \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=		IO::All::FTP.3 \
		IO::All::HTTP.3 \
		IO::All::HTTPS.3 \
		IO::All::LWP.3

NO_STAGE=	yes
.include <bsd.port.mk>
