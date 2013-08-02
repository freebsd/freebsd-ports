# $FreeBSD$

PORTNAME=	rpm-build-perl
PORTVERSION=	0.82
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ATOURBIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module is required to build Perl RPM packages

TEST_DEPENDS=	p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

MAN1=		perl.prov.1 \
		perl.req.1
MAN3=		B::Clobbers.3 \
		B::ConstOptree.3 \
		B::PerlReq.3 \
		B::Walker.3 \
		PerlReq::Utils.3

post-patch:
	@${REINPLACE_CMD} -e 's| perl.clean||' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
