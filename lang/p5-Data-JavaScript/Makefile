# New ports collection makefile for:	p5-Data-JavaScript
# Date created:				09 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Data-JavaScript
PORTVERSION=	1.11
CATEGORIES=	lang www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Data::JavaScript - Dump perl structures to JavaScript code

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PERL_CONFIGURE=	yes

MAN3=		Data::JavaScript.3

.include <bsd.port.mk>
