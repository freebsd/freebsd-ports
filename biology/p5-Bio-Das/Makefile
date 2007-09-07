# New ports collection makefile for:	p5-Bio-Das
# Date created:				17 January 2005
# Whom:					Razi Khaja <razi@genet.sickkids.on.ca>
#
# $FreeBSD$
#

PORTNAME=	Bio-Das
PORTVERSION=	1.06
CATEGORIES=	biology
MASTER_SITES=	http://www.biodas.org/download/Bio::Das/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Bio
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client-side library for Distributed Genome Annotation System

BUILD_DEPENDS=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Bio/Root/Root.pm:${PORTSDIR}/biology/p5-bioperl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

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
