# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	fpdns
PORTVERSION=	0.10.0.${GH_TAGNAME}
CATEGORIES=	dns net perl5
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fingerprinting DNS servers

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS

USE_GITHUB=	yes
GH_ACCOUNT=	kirei
GH_COMMIT=	23eb0bf
GH_TAGNAME=	20130404

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
