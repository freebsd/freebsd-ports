# $FreeBSD$

PORTNAME=	Store-CouchDB
PORTVERSION=	4.3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEV
PKGNAMEPREFIX=	p5-

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl interface to Apache CouchDB

LICENSE=	ART10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Data-Printer>=0:devel/p5-Data-Printer \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-libwww>=0:www/p5-libwww \
		p5-Types-Serialiser>=0:devel/p5-Types-Serialiser \
		p5-URI-Escape-XS>=0:www/p5-URI-Escape-XS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
