# New ports collection makefile for:	p5-Locale-Maketext-Lexicon
# Date created:				February 23, 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext-Lexicon
PORTVERSION=	0.64
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Use other catalog formats in Locale::Maketext

BUILD_DEPENDS=	${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Locale::Maketext::Extract.3 \
		Locale::Maketext::Extract::Run.3 \
		Locale::Maketext::Lexicon::Auto.3 \
		Locale::Maketext::Lexicon::Gettext.3 \
		Locale::Maketext::Lexicon::Msgcat.3 \
		Locale::Maketext::Lexicon::Tie.3 \
		Locale::Maketext::Lexicon.3

MAN1=		xgettext.pl.1

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
