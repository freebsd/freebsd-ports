# New ports collection makefile for:	fpdns
# Date Created:				July 2 2004
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	fpdns
PORTVERSION=	0.9.3.20120719
CATEGORIES=	dns net perl5
MASTER_SITES=	https://github.com/kirei/fpdns/tarball/9eb38df/
DISTNAME=	kirei-fpdns-${GITVERSION}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	FPDNS - Fingerprinting DNS servers

FETCH_ARGS=	-Fpr
GITVERSION=	9eb38df

RUN_DEPENDS=	p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS

PERL_CONFIGURE=	yes

MAN1=		fpdns.1

.include <bsd.port.mk>
