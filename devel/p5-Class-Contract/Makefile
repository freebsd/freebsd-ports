# New ports collection makefile for:	Class::Contract
# Date created:		5 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Contract
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	dos2unix:${PORTSDIR}/converters/unix2dos

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::Contract.3 Class::Contract::Production.3

post-extract:
	@find ${WRKSRC} -type f -name "*.p[lm]" | xargs dos2unix -p

pre-configure:
	${MKDIR} ${WRKSRC}/examples
	${MV} ${WRKSRC}/demo.pl ${WRKSRC}/examples

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* \
		${PREFIX}/share/examples/${PORTNAME}
.endif

.include <bsd.port.mk>
