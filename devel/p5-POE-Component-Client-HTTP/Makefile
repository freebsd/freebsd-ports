# New ports collection makefile for:	POE-Component-Client-HTTP
# Date created:		10 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-HTTP
PORTVERSION=	0.43
CATEGORIES=	devel perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://poe.perl.org/poedown/
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Net/SSLeay/Handle.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::Client::HTTP.3 POE::Component::Client::SSL.3

.include <bsd.port.mk>
