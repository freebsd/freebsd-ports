# New ports collection makefile for:	devel/p5-Set-Object
# Date created:				02 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Set-Object
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to manage sets of objects

PERL_CONFIGURE=	yes

MAN3=		Set::Object.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_DEPEND=	${SITE_PERL}/${PERL_ARCH}/Devel/Peek.pm:${PORTSDIR}/devel/p5-Devel-Peek
BUILD_DEPENDS+=	${EXTRA_DEPEND}
RUN_DEPENDS+=	${EXTRA_DEPEND}
.endif

.include <bsd.port.post.mk>
