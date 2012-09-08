# New ports collection makefile for:	devel/p5-Sub-WrapPackages
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	Sub-WrapPackages
PORTVERSION=	2.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Add pre- and post-execution wrappers

RUN_DEPENDS=	p5-Hook-LexWrap>=0:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-Devel-Caller-IgnoreNamespaces>=1:${PORTSDIR}/devel/p5-Devel-Caller-IgnoreNamespaces \
		p5-Sub-Prototype>=0.02:${PORTSDIR}/devel/p5-Sub-Prototype
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Sub::WrapPackages.3

.include <bsd.port.mk>
