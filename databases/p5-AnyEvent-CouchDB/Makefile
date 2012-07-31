# New ports collection makefile for:	p5-AnyEvent-CouchDB
# Date created:		2011-09-03
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-CouchDB
PORTVERSION=	1.29
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A non-blocking CouchDB client based on jquery.couch.js

LICENSE=	MIT

BUILD_DEPENDS=	couchdb>=0.9.0:${PORTSDIR}/databases/couchdb \
		p5-AnyEvent-HTTP>=2.11:${PORTSDIR}/www/p5-AnyEvent-HTTP \
		p5-CouchDB-View>=0:${PORTSDIR}/databases/p5-CouchDB-View \
		p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON \
		p5-Scope-Guard>=0:${PORTSDIR}/devel/p5-Scope-Guard
BUILD_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		couchdb-push.1
MAN3=		AnyEvent::CouchDB.3 \
		AnyEvent::CouchDB::Database.3 \
		AnyEvent::CouchDB::Exceptions.3 \
		AnyEvent::CouchDB::Stream.3

.include <bsd.port.mk>
