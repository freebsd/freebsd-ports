# New ports collection makefile for:	POE-Component-RRDTool
# Date created:	   05 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-RRDTool
PORTVERSION=	0.18
CATEGORIES=	net perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE interface to Round Robin Database Tools

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${LOCALBASE}/bin/rrdtool:${PORTSDIR}/net/rrdtool
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MAN3=		POE::Component::RRDTool.3

post-patch:
	@${PERL} -pi -e 's/(\(\$$maj, \$$min, \$$sub\))/$$1; $$1/' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
