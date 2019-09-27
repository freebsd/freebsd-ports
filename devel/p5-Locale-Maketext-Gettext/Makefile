# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Locale-Maketext-Gettext
PORTVERSION=	1.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Joins gettext and Maketext frameworks

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	BUGS Changes README THANKS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
