# New ports collection makefile for:    p5-DBD-Sybase
# Date created:				May 10th 2001
# Whom:	      				Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Sybase
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Sybase DBI driver for Perl 5

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	ct.4:${PORTSDIR}/databases/freetds

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	SYBASE=${LOCALBASE}

.if defined(BATCH)
CONFIGURE_ARGS+=	< /dev/null
.endif

USE_GETTEXT=	yes

MAN3=		DBD::Sybase.3

.include <bsd.port.mk>
