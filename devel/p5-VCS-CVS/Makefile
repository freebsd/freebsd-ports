# New ports collection makefile for:	p5-VCS-CVS
# Date created:				15 May 2001
# Whom:					Anatoliy Dmytriyev <tolid@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	VCS-CVS
PORTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	http://savage.net.au/Perl-modules/ \
		http://tolid.eu.org/VCSCVS/
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	tolid@plab.ku.dk
COMMENT=	Perl module that provides a simple interface to CVS

BUILD_DEPENDS=	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod

PERL_MODBUILD=	yes
MAN3=		VCS::CVS.3

.include <bsd.port.mk>
