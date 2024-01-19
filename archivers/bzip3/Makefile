PORTNAME=	bzip3
DISTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/kspalaiologos/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Better and stronger spiritual successor to BZip2
WWW=		https://github.com/kspalaiologos/bzip3

LICENSE=	APACHE20 BSD2CLAUSE LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/libsais-LICENSE
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE

USES=		cmake pathfix tar:xz
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|\(VERSION \)1\.3\.0|\1${DISTVERSION}|" \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
