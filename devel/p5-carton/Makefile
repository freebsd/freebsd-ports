# New ports collection makefile for:	carton
# Date created:		14 Oct 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	carton
PORTVERSION=	0.9.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module dependency manager

RUN_DEPENDS=	\
	p5-App-cpanminus>=1.5:${PORTSDIR}/devel/p5-App-cpanminus \
	p5-CPAN-Meta>=2.112:${PORTSDIR}/devel/p5-CPAN-Meta \
	p5-Exception-Class>=1.32:${PORTSDIR}/devel/p5-Exception-Class \
	p5-JSON>=2.53:${PORTSDIR}/converters/p5-JSON \
	p5-Module-Metadata>=1.000003:${PORTSDIR}/devel/p5-Module-Metadata \
	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-local-lib>=1.008:${PORTSDIR}/devel/p5-local-lib
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	carton-check.1 \
	carton-exec.1 \
	carton-faq.1 \
	carton-install.1 \
	carton-list.1 \
	carton-show.1 \
	carton-tree.1 \
	carton-uninstall.1 \
	carton-version.1 \
	carton.1
MAN3=	Carton.3 \
	Carton::Doc::Check.3 \
	Carton::Doc::Exec.3 \
	Carton::Doc::FAQ.3 \
	Carton::Doc::Install.3 \
	Carton::Doc::List.3 \
	Carton::Doc::Show.3 \
	Carton::Doc::Tree.3 \
	Carton::Doc::Uninstall.3 \
	Carton::Doc::Version.3

.include <bsd.port.mk>
