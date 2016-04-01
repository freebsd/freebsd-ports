# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpsl2acl
PORTVERSION=	1.00
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/dnstools/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Query set of RPSL database objects and convert to BIND ACLs

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Net-CIDR>0:net-mgmt/p5-Net-CIDR

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/rpsl2acl ${SITE_MAN1}/rpsl2acl.1.gz

.include <bsd.port.mk>
