# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	gbsdconv
PORTVERSION=	11.3
PORTREVISION=	1
CATEGORIES=	converters python

MAINTAINER=	buganini@gmail.com
COMMENT=	GUI for bsdconv

LICENSE=	ISCL

LIB_DEPENDS=	libtag.so:audio/taglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsdconv>=8.0:converters/py-bsdconv@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	buganini

USES=		gnome python shebangfix
USE_GNOME=	gtk30 introspection:run
SHEBANG_FILES=	gbsdconv

USE_LDCONFIG=	yes

PLIST_FILES=	bin/gbsdconv \
		lib/gbsdconv_taglib.so \
		%%DATADIR%%/gbsdconv.png \
		%%DATADIR%%/gbsdconv.xml \
		%%DATADIR%%/gbsdconv2.png

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gbsdconv_taglib.so

.include <bsd.port.mk>
