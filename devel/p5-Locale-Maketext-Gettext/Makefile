# New ports collection makefile for:	p5-Locale-Maketext-Gettext
# Date created:				April 26 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext-Gettext
PORTVERSION=	1.17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Joins gettext and Maketext frameworks

BUILD_DEPENDS=	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		maketext.1
MAN3=		Locale::Maketext::Gettext.3 \
		Locale::Maketext::Gettext::Functions.3

.if !defined(NOPORTDOCS)
PORTDOCS=	BUGS Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE="Need at least perl 5.8 to build"
.endif

.include <bsd.port.post.mk>
