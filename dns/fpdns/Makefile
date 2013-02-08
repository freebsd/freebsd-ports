# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	fpdns
PORTVERSION=	0.9.3.20121019
CATEGORIES=	dns net perl5
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	FPDNS - Fingerprinting DNS servers

RUN_DEPENDS=	p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS

USE_GITHUB=	yes
GH_ACCOUNT=	kirei
GH_COMMIT=	24a2f18
GH_TAGNAME=	${GH_COMMIT}

PERL_CONFIGURE=	yes

MAN1=		fpdns.1

.include <bsd.port.mk>
