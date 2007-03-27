# New ports collection makefile for:	p5-gearmand
# Date created:				Mon Mar 26 11:45:06 EDT 2007
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	gearmand
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Gearman server daemon

USE_RC_SUBR=	gearmand.sh
SUB_LIST+=	NAME=gearmand

MODULE_DEPENDS=	p5-Gearman>=1.0:${PORTSDIR}/devel/p5-Gearman \
		p5-Danga-Socket>=1.52:${PORTSDIR}/devel/p5-Danga-Socket
RUN_DEPENDS+=	${MODULE_DEPENDS}
BUILD_DEPENDS+=	${MODULE_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		gearmand.1
PLIST_FILES=	bin/gearmand \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/gearmand/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/gearmand

.include <bsd.port.mk>
