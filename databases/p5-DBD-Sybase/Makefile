# New ports collection makefile for:    p5-DBD-Sybase
# Date created:				May 10th 2001
# Whom:	      				Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Sybase
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	sheldonh@FreeBSD.org
COMMENT=	A Sybase DBI driver for Perl 5

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	ct.1:${PORTSDIR}/databases/freetds \
		intl.5:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	SYBASE=${LOCALBASE}

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::Sybase.3

.include <bsd.port.mk>
