# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Amazon-Route53
PORTVERSION=	0.122310
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Manage your DNS entries on Amazon's Route53 service

CONFLICTS=	py[23][0-9]-boto-devel-[0-9]*

RUN_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-XML-Bare>=0:${PORTSDIR}/textproc/p5-XML-Bare \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN1=		route53.1
MAN3=		Net::Amazon::Route53.3 \
		Net::Amazon::Route53::HostedZone.3 \
		Net::Amazon::Route53::ResourceRecordSet.3 \
		Net::Amazon::Route53::ResourceRecordSet::Change.3 \
		Net::Amazon::Route53::Change.3

.include <bsd.port.mk>
