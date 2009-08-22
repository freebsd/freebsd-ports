# Ports collection makefile for:	p5-MIME-Base64-URLSafe
# Date created:	   Fri Aug 21, 2009
# Whom:		   Dan Rench <citric@cubicone.tmetic.com>
#
# $FreeBSD$
#

PORTNAME=	MIME-Base64-URLSafe
PORTVERSION=	0.01
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	citric@cubicone.tmetic.com
COMMENT=	Perl version of Python's URL-safe base64 codec

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
BUILD_DEPENDS=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME:S/00//}

PERL_CONFIGURE=	yes

MAN3=		MIME::Base64::URLSafe.3

.include <bsd.port.mk>
