# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Locale-Maketext-Gettext
PORTVERSION=	1.28
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Joins gettext and Maketext frameworks

USES=		perl5
USE_PERL5=	configure

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
