# New ports collection makefile for:	p5-File-Spec
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	File-Spec
PORTVERSION=	0.82
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	dburr@FreeBSD.ORG

PERL_CONFIGURE=	yes

MAN3=		File::Spec.3 \
		File::Spec::Functions.3 \
		File::Spec::Mac.3 \
		File::Spec::OS2.3 \
		File::Spec::Unix.3 \
		File::Spec::VMS.3 \
		File::Spec::Win32.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
