# New ports collection makefile for:	p5-File-Spec
# Date created:				November 22, 2000
# Whom:	      				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	File-Spec
PORTVERSION=	0.90
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl module for portably manipulating file specifications

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INSTALLDIRS='site'

MAN3=		File::Spec.3 \
		File::Spec::Cygwin.3 \
		File::Spec::Epoc.3 \
		File::Spec::Functions.3 \
		File::Spec::Mac.3 \
		File::Spec::OS2.3 \
		File::Spec::Unix.3 \
		File::Spec::VMS.3 \
		File::Spec::Win32.3

.include <bsd.port.mk>
