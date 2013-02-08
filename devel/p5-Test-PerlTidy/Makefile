# $FreeBSD$

PORTNAME=	Test-PerlTidy
PORTVERSION=	20130104
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to check that all your files are tidy

RUN_DEPENDS=	\
	p5-File-Finder>0:${PORTSDIR}/devel/p5-File-Finder \
	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
	perltidy>=20121207:${PORTSDIR}/devel/perltidy \
	p5-Text-Diff>0:${PORTSDIR}/textproc/p5-Text-Diff
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::PerlTidy.3

.include <bsd.port.mk>
