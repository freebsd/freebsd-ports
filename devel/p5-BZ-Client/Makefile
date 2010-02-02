# New ports collection makefile for:	BZ-Client
# Date created:	   26 Jan 2010
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	BZ-Client
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JW/JWIED
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Client for the Bugzilla web services API

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.10.1+

MAN3=		BZ::Client.3 BZ::Client::API.3 BZ::Client::Bug.3 \
		BZ::Client::Bugzilla.3 BZ::Client::Exception.3 \
		BZ::Client::Product.3 BZ::Client::Test.3 BZ::Client::XMLRPC.3

post-patch:
	@${REINPLACE_CMD} -i '' -E 's=(api_call\()"=\1$$client, "=' \
		${WRKSRC}/lib/BZ/Client/Bug.pm

.include <bsd.port.mk>
