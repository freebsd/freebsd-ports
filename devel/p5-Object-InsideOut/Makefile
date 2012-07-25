# New ports collection makefile for:	devel/p5-Object-InsideOut
# Date created:				15 January 2006
# Whom:					Geraud Continsouzas <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	Object-InsideOut
PORTVERSION=	3.95
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Object::InsideOut - Comprehensive inside-out object support module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Dumper>=2.131:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Exception-Class>=1.32:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Want>=0.21:${PORTSDIR}/devel/p5-Want
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bundle::Object::InsideOut.3 \
		Object::InsideOut.3 \
		Object::InsideOut::Metadata.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.25:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.25:${PORTSDIR}/lang/p5-Scalar-List-Utils
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
