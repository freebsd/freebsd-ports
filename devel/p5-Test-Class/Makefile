# New ports collection makefile for:    p5-Test-Class
# Date created:				January 27th 2003
# Whom:	      				Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Test-Class
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk
COMMENT=	Test::Class - Easily create test classes in an xUnit style

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Attribute/Handlers.pm:${PORTSDIR}/devel/p5-Attribute-Handlers \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/Builder/Tester.pm:${PORTSDIR}/devel/p5-Test-Builder-Tester \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/Differences.pm:${PORTSDIR}/devel/p5-Test-Differences
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Test::Class.3

.include <bsd.port.pre.mk>

##
## this port requires PERL 5.6.x or later
##
.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
