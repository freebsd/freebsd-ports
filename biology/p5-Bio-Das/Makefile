# Created by: Razi Khaja <razi@genet.sickkids.on.ca>
# $FreeBSD$

PORTNAME=	Bio-Das
PORTVERSION=	1.17
PORTREVISION=	2
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client-side library for Distributed Genome Annotation System

RUN_DEPENDS=	p5-HTML-Parser>=3:${PORTSDIR}/www/p5-HTML-Parser \
		p5-bioperl>=0:${PORTSDIR}/biology/p5-bioperl \
		p5-libwww>=5:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Bio::Das.3 Bio::Das::AGPServer::Config.3 Bio::Das::AGPServer::Daemon.3 \
	Bio::Das::AGPServer::Parser.3 Bio::Das::AGPServer::SQLStorage.3 \
	Bio::Das::AGPServer::SQLStorage::CSV::DB.3 \
	Bio::Das::AGPServer::SQLStorage::MySQL::DB.3 \
	Bio::Das::DSN.3 Bio::Das::Feature.3 Bio::Das::FeatureIterator.3 \
	Bio::Das::HTTP::Fetch.3 Bio::Das::Map.3 Bio::Das::Request.3 \
	Bio::Das::Request::Dnas.3 Bio::Das::Request::Dsn.3 \
	Bio::Das::Request::Entry_points.3 Bio::Das::Request::Feature2Segments.3 \
	Bio::Das::Request::Sequences.3 Bio::Das::Request::Stylesheet.3 \
	Bio::Das::Request::Types.3 Bio::Das::Segment.3 Bio::Das::Stylesheet.3 \
	Bio::Das::Type.3 Bio::Das::TypeHandler.3 Bio::Das::Util.3

.include <bsd.port.mk>
