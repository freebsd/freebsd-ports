# New ports collection makefile for:	Class-Fields
# Date created:		15 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Fields
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS='site'

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::Fields.3 Class::Fields::Attribs.3 \
		Class::Fields::Fuxor.3 Class::Fields::Inherit.3 base.3 \
		fields.3 private.3 protected.3 public.3

.include <bsd.port.mk>
