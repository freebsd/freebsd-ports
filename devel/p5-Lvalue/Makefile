# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lvalue
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add lvalue getters and setters to existing objects

BUILD_DEPENDS=	p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
    		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch::
	@${REINPLACE_CMD} -e 's|qw(can isa DOES VERSION)|(qw(can isa DOES VERSION))|g' \
		${WRKSRC}/lib/Lvalue.pm
	@${RM} ${WRKSRC}/lib/Lvalue.pm.bak

.include <bsd.port.mk>
