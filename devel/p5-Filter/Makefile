# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Filter
PORTVERSION=	1.49
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RURBAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Number of source filters for perl5 programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

MAN3=		Filter::Util::Call.3 \
		Filter::Util::Exec.3 \
		Filter::Util::perlfilter.3 \
		Filter::cpp.3 \
		Filter::decrypt.3 \
		Filter::exec.3 \
		Filter::sh.3 \
		Filter::tee.3

.include <bsd.port.mk>
