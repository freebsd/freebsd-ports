# New ports collection makefile for:	kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
PORTVERSION=	1.3
CATEGORIES=	editors kde
MASTER_SITES=	http://xm1.net.free.fr/kile/
DISTNAME=	${PORTNAME}-${PORTVERSION}beta

MAINTAINER=	stefan.jahn@nemesis-sektor.de

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
