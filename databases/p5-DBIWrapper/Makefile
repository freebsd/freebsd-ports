# New ports collection makefile for:	dbiwrapper
# Date Created:				30 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	dbiwrapper
PORTVERSION=	0.11
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	dbi_wrapper-${PORTVERSION}

MAINTAINER=	petef@databits.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

USE_PERL5=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	DBIWrapper.3

.include <bsd.port.mk>
