# New ports collection makefile for:	Data::UUID
# Date created:		28 Jan 2002
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-UUID
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Module for generating Globally/Universally Unique Identifiers (GUIDs/UUIDs)

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	</dev/null

MAN3=		Data::UUID.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
