# New ports collection makefile for:	Ima-DBI
# Date created:		17 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Ima-DBI
PORTVERSION=	0.27
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class/TMTM
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/WhiteHole.pm:${PORTSDIR}/devel/p5-Class-WhiteHole \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Ima::DBI.3

.include <bsd.port.mk>
