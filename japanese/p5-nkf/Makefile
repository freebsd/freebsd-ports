# New ports collection makefile for:	p5-nkf
# Date created:		23 Feb 2000
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	2.02
CATEGORIES=	japanese perl5
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/
PKGNAMEPREFIX=	ja-p5-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//:S/./-/}

MAINTAINER=	max@FreeBSD.org
COMMENT=	A perl extension module to use NKF

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/NKF.mod
MAN3=		NKF.3

.include <bsd.port.mk>
