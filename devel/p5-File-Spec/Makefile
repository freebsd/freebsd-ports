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

.include <bsd.port.pre.mk>

perl_major=${PERL_VERSION:C|^([1-9]+).*|\1|}
_perl_minor=00${PERL_VERSION:C|^([1-9]+)\.([0-9]+).*|\2|}
perl_minor=${_perl_minor:C|^.*(...)|\1|}
.if ${perl_minor} >= 100
perl_minor=${PERL_VERSION:C|^([1-9]+)\.([0-9][0-9][0-9]).*|\2|}
perl_patch=${PERL_VERSION:C|^.*(..)|\1|}
.else # ${perl_minor} < 100
_perl_patch=0${PERL_VERSION:C|^([1-9]+)\.([0-9]+)\.*|0|}
perl_patch=${_perl_patch:C|^.*(..)|\1|}
.endif # ${perl_minor} < 100
PERL_LEVEL=${perl_major}${perl_minor}${perl_patch}

.if ${PERL_LEVEL} > 500600
FORBIDDEN=	This port is for perl 5.6.0 and under only.
.endif # ${PERL_LEVEL} > 500600

.include <bsd.port.post.mk>
