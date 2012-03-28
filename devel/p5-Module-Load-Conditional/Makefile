# New ports collection makefile for:	devel/p5-Module-Load-Conditional
# Date created:				15 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Load-Conditional
PORTVERSION=	0.48
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Looking up Perl modules information/loading at runtime

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-CoreList>=2.22:${PORTSDIR}/devel/p5-Module-CoreList
RUN_DEPENDS=	p5-Module-CoreList>=2.22:${PORTSDIR}/devel/p5-Module-CoreList

PERL_CONFIGURE=	yes

MAN3=		Module::Load::Conditional.3
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load>=0.11:${PORTSDIR}/devel/p5-Module-Load \
		p5-Params-Check>=0:${PORTSDIR}/devel/p5-Params-Check \
		p5-version>=0.69:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load>=0.11:${PORTSDIR}/devel/p5-Module-Load \
		p5-Params-Check>=0:${PORTSDIR}/devel/p5-Params-Check \
		p5-version>=0.69:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
