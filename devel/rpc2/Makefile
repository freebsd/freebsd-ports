# New ports collection makefile for:	rpc2
# Date created:				Wed Mar 22 19:06:45 EST 2000
# Whom:					jaharkes
#
# $FreeBSD$
#

PORTNAME=	rpc2
PORTVERSION=	1.22
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/

MAINTAINER=	coda@cs.cmu.edu
COMMENT=	An interprocess communication library

LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp

USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=  yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
