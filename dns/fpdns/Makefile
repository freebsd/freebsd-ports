# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	fpdns
PORTVERSION=	0.10.0.${GH_TAGNAME}
PORTREVISION=	1
CATEGORIES=	dns net perl5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fingerprinting DNS servers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	kirei
GH_TAGNAME=	20130404

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
