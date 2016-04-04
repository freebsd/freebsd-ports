# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnsdbck
PORTVERSION=	1.00
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/dnstools/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Verify consistency of DNS information in an SQL database

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Net-CIDR>0:net-mgmt/p5-Net-CIDR \
		p5-Net-DNS>0:dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/dnsdbck ${SITE_MAN1}/dnsdbck.1.gz

.include <bsd.port.mk>
