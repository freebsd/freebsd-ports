# New ports collection makefile for:	Data::Util
# Date created:		23 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Util
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for utilities for data and data types

RUN_DEPENDS=	\
	p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat

PERL_CONFIGURE=	yes

MAN3=		Data::Util.3 \
		Data::Util::Curry.3 \
		Data::Util::Error.3 \
		Data::Util::JA.3 \
		Data::Util::PurePerl.3

.include <bsd.port.mk>
