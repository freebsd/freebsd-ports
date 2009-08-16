# New ports collection makefile for:	p5-Locale-Maketext-Gettext
# Date created:				April 26 2003
# Whom:					Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext-Gettext
PORTVERSION=	1.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Joins gettext and Maketext frameworks

BUILD_DEPENDS=	${SITE_PERL}/Locale/Maketext.pm:${PORTSDIR}/devel/p5-Locale-Maketext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		maketext.1
MAN3=		Locale::Maketext::Gettext.3 \
		Locale::Maketext::Gettext::Functions.3

.if !defined(NOPORTDOCS)
PORTDOCS=	BUGS Changes README THANKS

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
