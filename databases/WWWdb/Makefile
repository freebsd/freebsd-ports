# New ports collection makefile for:	WWWdb
# Date created:		Wed Nov 20 11:37:33 CET 2002
# Whom:			Jens Rehsack <rehsack@liwing.de>
#
# $FreeBSD$
#

PORTNAME=	WWWdb
PORTVERSION=	0.8.3
CATEGORIES=	databases perl5 www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wwwdb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl based generic WWW DB interface / frontend

PERL_CONFIGURE=	yes

MAN3=		WWWdb::Base.3 WWWdb::DbSession.3 WWWdb::List.3 \
		WWWdb::Session.3 WWWdb::Plugin.3 WWWdb::Hash.3 \
		WWWdb::HTML.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600
MAN3+=		WWWdb::ConfigFile.3 WWWdb::ConfigPool.3
.endif

.include <bsd.port.post.mk>
