PORTNAME=	yandex-ddns
DISTVERSION=	g20200613
PORTREVISION=	27
CATEGORIES=	dns

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use Yandex DNS as a dynamic DNS provider
WWW=		https://github.com/thekvs/yandex-ddns

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	thekvs
GH_TAGNAME=	1fd0d00

PLIST_FILES=	bin/yandex-ddns\
		${EXAMPLESDIR}/yandex-ddns.example.toml

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/yandex-ddns.example.toml \
	${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
