# New ports collection makefile for:    p5-DBD-Sybase
# Date created:				May 10th 2001
# Whom:	      				Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Sybase
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Sybase DBI driver for Perl 5

LIB_DEPENDS=	ct.2:${PORTSDIR}/databases/freetds

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	SYBASE=${LOCALBASE}
USE_GETTEXT=	yes

MAN3=		DBD::Sybase.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
