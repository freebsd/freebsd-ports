# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	renewck
PORTVERSION=	1.00
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/dnstools/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Check for expiring domains and send email notifications

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Time-modules>0:devel/p5-Time-modules \
		p5-Mail-Tools>0:mail/p5-Mail-Tools \
		p5-GDBM>0:databases/p5-GDBM

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/renewck ${SITE_MAN1}/renewck.1.gz

.include <bsd.port.mk>
