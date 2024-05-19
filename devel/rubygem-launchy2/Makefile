PORTNAME=	launchy
PORTVERSION=	2.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper class for launching cross-platform applications
WWW=		https://github.com/copiousfreetime/launchy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/launchy

.include <bsd.port.mk>
