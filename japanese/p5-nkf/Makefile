# New ports collection makefile for:	p5-nkf
# Date created:		23 Feb 2000
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	2.03
CATEGORIES=	japanese perl5
MASTER_SITES=	http://www.ie.u-ryukyu.ac.jp/~kono/nkf/dist/
PKGNAMEPREFIX=	ja-p5-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//:S/./-/}
EXTRACT_SUFX=	.tar

MAINTAINER=	max@FreeBSD.org
COMMENT=	A perl extension module to use NKF

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/NKF.mod
MAN3=		NKF.3

.include <bsd.port.mk>
