PORTNAME=	qwdtools
PORTVERSION=	0.34.20220905
PORTEPOCH=	2
CATEGORIES=	games converters

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Convert QuakeWorld demos from QWD format to MVD format
WWW=		https://github.com/QW-Group/qwdtools

LICENSE=	GPLv2+

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	QW-Group
GH_TAGNAME=	8af104b

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
