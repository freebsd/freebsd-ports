# New ports collection makefile for:	BZ-Client
# Date created:	   26 Jan 2010
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	BZ-Client
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JW/JWIED
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Client for the Bugzilla web services API

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.10.1+

MAN3=		BZ::Client.3 BZ::Client::API.3 BZ::Client::Bug.3 \
		BZ::Client::Bugzilla.3 BZ::Client::Exception.3 \
		BZ::Client::Product.3 BZ::Client::Test.3 BZ::Client::XMLRPC.3

.include <bsd.port.mk>
