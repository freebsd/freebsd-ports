# ports collection makefile for:	p5-Imlib2
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	Imlib2
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.muhri.net/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl bindings for Imlib2

USE_EFL=	imlib2

PERL_CONFIGURE=	yes

MAN3=		Imlib2.3

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
