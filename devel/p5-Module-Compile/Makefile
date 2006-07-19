# New ports collection makefile for:	p5-Module-Compile
# Date created:				2006-05-30
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Module-Compile
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Provide a system for writing modules that compile other Perl modules

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Compile.3 \
		Module::Install::Admin::PMC.3 \
		Module::Install::PMC.3\
		Module::Optimize.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800 # inherited from dependency upon Filter/Util/Call.pm
IGNORE=		requires perl 5.8 or above
.endif

.include <bsd.port.post.mk>
