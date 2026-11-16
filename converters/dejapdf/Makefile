PORTNAME=	dejapdf
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.72
CATEGORIES=	converters

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MAINTAINER=	osa@FreeBSD.org
COMMENT=	DjVu to PDF converter
WWW=		https://github.com/sergev/dejapdf

USES=		go:no_targets

USE_GITHUB=	yes
GH_ACCOUNT=	sergev

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
