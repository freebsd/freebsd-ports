# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpsl2acl
PORTVERSION=	1.01
CATEGORIES=	dns perl5
MASTER_SITES=	http://download.gnu.org.ua/pub/release/dnstools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Query set of RPSL database objects and convert to BIND ACLs

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Net-CIDR>0:net-mgmt/p5-Net-CIDR

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PLIST_FILES=	bin/rpsl2acl ${SITE_MAN1}/rpsl2acl.1.gz

.include <bsd.port.mk>
