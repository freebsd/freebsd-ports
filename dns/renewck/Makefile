# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	renewck
PORTVERSION=	1.01
CATEGORIES=	dns perl5
MASTER_SITES=	http://download.gnu.org.ua/pub/release/dnstools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check for expiring domains and send email notifications

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Time-modules>0:devel/p5-Time-modules \
		p5-Mail-Tools>0:mail/p5-Mail-Tools \
		p5-GDBM>0:databases/p5-GDBM

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PLIST_FILES=	bin/renewck ${SITE_MAN1}/renewck.1.gz

.include <bsd.port.mk>
