# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-CouchDB
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-blocking CouchDB client based on jquery.couch.js

LICENSE=	MIT

BUILD_DEPENDS=	couchdb>=0.9.0:databases/couchdb \
		p5-AnyEvent-HTTP>=2.11:www/p5-AnyEvent-HTTP \
		p5-CouchDB-View>=0:databases/p5-CouchDB-View \
		p5-Data-Dump-Streamer>=0:devel/p5-Data-Dump-Streamer \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-JSON>=2:converters/p5-JSON \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard
BUILD_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
