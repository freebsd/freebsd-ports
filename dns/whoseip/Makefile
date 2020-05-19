# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	whoseip
PORTVERSION=	1.00
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/dnstools/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Get information about IP addresses: country code and network

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Net-CIDR>0:net-mgmt/p5-Net-CIDR \
		p5-Data-UUID>0:devel/p5-Data-UUID

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
