# New ports collection makefile for:	Package-DeprecationManager
# Date created:				05 August 2010
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	Package-DeprecationManager
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Manage deprecation warnings for your distribution

BUILD_DEPENDS=	p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS=	p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Install>=0:${PORTSDIR}/devel/p5-Sub-Install \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils

LICENSE=	ART20

PERL_CONFIGURE=	yes

MAN3=		Package::DeprecationManager.3

post-extract:
	@${PERL} -i -ne "print unless /'BUILD_REQUIRES'/../},/" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
