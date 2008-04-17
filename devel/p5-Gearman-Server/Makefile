# New ports collection makefile for:	p5-Gearman-Server
# Date created:		2007-09-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Gearman-Server
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Gearman server daemon

RUN_DEPENDS=	p5-Gearman>=1.0:${PORTSDIR}/devel/p5-Gearman \
		p5-Danga-Socket>=1.52:${PORTSDIR}/devel/p5-Danga-Socket
BUILD_DEPENDS+=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	gearmand.1
MAN3=	Gearman::Server.3 Gearman::Server::Client.3

USE_RC_SUBR=	gearmand
SUB_LIST+=	NAME=gearmand

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
