# New ports collection makefile for:	p5-Archive-Any
# Date created:		2006-08-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Archive-Any
PORTVERSION=	0.09.3
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Archive
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.093

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Single interface to deal with file archives

RUN_DEPENDS=	${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Archive-Tar>=0.22:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Archive-Zip>=1.07:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-File-MMagic>=1.27:${PORTSDIR}/devel/p5-File-MMagic \
		p5-Module-Find>=0.05:${PORTSDIR}/devel/p5-Module-Find
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Archive::Any.3 Archive::Any::Plugin.3 \
		Archive::Any::Plugin::Tar.3 Archive::Any::Plugin::Zip.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from dependencies
IGNORE=		requires Perl 5.6.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
