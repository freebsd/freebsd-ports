# New ports collection makefile for:	WWWdb
# Date created:		Wed Nov 20 11:37:33 CET 2002
# Whom:			Jens Rehsack <rehsack@liwing.de>
#
# $FreeBSD$
#

PORTNAME=	WWWdb
PORTVERSION=	0.8.2
CATEGORIES=	databases perl5 www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wwwdb

MAINTAINER=	rehsack@liwing.de
COMMENT=	A Perl based generic WWW DB interface / frontend

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWWdb::Base.3 \
		WWWdb::DbSession.3 \
		WWWdb::List.3 \
		WWWdb::Session.3 \
		WWWdb::Plugin.3 \
		WWWdb::Hash.3 \
		WWWdb::HTML.3 \

.include <bsd.port.mk>
