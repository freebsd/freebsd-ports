# New ports collection makefile for:	devel/p5-Rcs-Agent
# Date created:				28 October 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Rcs-Agent
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Rcs
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Rcs::Agent.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -pi \
		-e 's/MkTemp/Temp/;' \
		-e 's/^(.*)=.*mktemp.*"(.*)".*$$/$$1 = File::Temp::mktemp("\$$tmpdir\/$$2");/;' \
		${WRKSRC}/Agent.pm ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
