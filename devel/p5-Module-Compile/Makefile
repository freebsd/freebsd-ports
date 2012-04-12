# New ports collection makefile for:	p5-Module-Compile
# Date created:				2006-05-30
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Module-Compile
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Provide a system for writing modules that compile other Perl modules

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Compile.3 \
		Module::Compile::Opt.3 \
		Module::Install::Admin::PMC.3 \
		Module::Install::PMC.3\
		Module::Optimize.3

.include <bsd.port.mk>
