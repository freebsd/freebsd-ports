# New ports collection makefile for:	p5-Archive-Any
# Date created:		2006-08-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Archive-Any
PORTVERSION=	0.09.32
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Single interface to deal with file archives

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=1.07:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-File-MMagic>=1.27:${PORTSDIR}/devel/p5-File-MMagic \
		p5-MIME-Types>=1.16:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Module-Find>=0.05:${PORTSDIR}/devel/p5-Module-Find
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=		Archive::Any.3 Archive::Any::Plugin.3 \
		Archive::Any::Plugin::Tar.3 Archive::Any::Plugin::Zip.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Archive-Tar>=0.22:${PORTSDIR}/archivers/p5-Archive-Tar
RUN_DEPENDS+=	p5-Archive-Tar>=0.22:${PORTSDIR}/archivers/p5-Archive-Tar
.endif

.include <bsd.port.post.mk>
