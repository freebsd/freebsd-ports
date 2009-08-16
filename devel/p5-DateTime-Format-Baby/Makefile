# New ports collection makefile for:	p5-DateTime-Format-Baby
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Baby
PORTVERSION=	1.0100
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format baby-style time

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
BUILD_DEPENDS=	${RUN_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME:S/00//}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::Baby.3

.include <bsd.port.mk>
