# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vhostcname
PORTVERSION=	1.00
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/dnstools/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Synchronize DNS with server names and aliases from Apache vhost

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Net-DNS>0:dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/vhostcname ${SITE_MAN1}/vhostcname.1.gz

.include <bsd.port.mk>
