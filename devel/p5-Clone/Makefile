# New ports collection makefile for:	devel/p5-Clone
# Date created:				05 June 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Clone
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Clone
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Clone.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	${PERL} -pi -e 'm.OPTIMIZE.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
