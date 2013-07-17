# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	Gearman-Server
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Gearman server daemon

RUN_DEPENDS=	p5-Gearman>=1.10:${PORTSDIR}/devel/p5-Gearman \
		p5-Danga-Socket>=1.52:${PORTSDIR}/devel/p5-Danga-Socket

CONFLICTS=	gearmand-0.* gearmand-1.0.* gearmand-1.1.*

PERL_CONFIGURE=	yes

MAN1=	gearmand.1
MAN3=	Gearman::Server.3 Gearman::Server::Client.3

USE_RC_SUBR=	gearmand-perl
SUB_LIST+=	NAME=gearmand

.include <bsd.port.mk>
