# New ports collection makefile for:    p5-rpm-build-perl
# Date created:				2006-07-12
# Whom:	      				Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	rpm-build-perl
PORTVERSION=	0.76
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ATOURBIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module is required to build Perl RPM packages

PERL_CONFIGURE=	yes

MAN1=		perl.prov.1 perl.req.1
MAN3=		B::Clobbers.3 B::PerlReq.3 B::Walker.3 PerlReq::Utils.3

post-patch:
	@${REINPLACE_CMD} -e 's| perl.clean||' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
