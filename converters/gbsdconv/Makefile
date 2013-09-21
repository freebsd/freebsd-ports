# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	gbsdconv
PORTVERSION=	11.1
CATEGORIES=	converters python
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	GUI for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsdconv>=8.0:${PORTSDIR}/converters/py-bsdconv \
		${LOCALBASE}/bin/g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	0a9ad34

USE_GNOME=	gtk30
USE_PYTHON=	yes

USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX=${PREFIX}
NO_STAGE=	yes

PLIST_FILES=	bin/gbsdconv \
		lib/gbsdconv_taglib.so \
		%%DATADIR%%/gbsdconv.png \
		%%DATADIR%%/gbsdconv.xml \
		%%DATADIR%%/gbsdconv2.png
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/gbsdconv

.include <bsd.port.mk>
