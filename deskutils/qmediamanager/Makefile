PORTNAME=	qmediamanager
DISTVERSION=	0.1.1-2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g2dc5c7b
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GUI tool for managing removable media
WWW=		https://github.com/outpaddling/qmediamanager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxtend>=0.1.8:devel/libxtend
LIB_DEPENDS=	libxtend.so:devel/libxtend
RUN_DEPENDS=	npmount>0:sysutils/npmount \
		devd-mount>0:sysutils/devd-mount \
		auto-admin>=0.8.0:sysutils/auto-admin \
		rxvt-unicode>0:x11/rxvt-unicode

USES=		gl qmake qt:6
USE_QT=		base tools:build
USE_GL=		gl
USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

PLIST_FILES=	bin/qmediamanager share/man/man1/qmediamanager.1.gz

do-install:
	${INSTALL} -c ${WRKSRC}/qmediamanager ${STAGEDIR}${PREFIX}/bin
	${INSTALL} -c ${WRKSRC}/Man/qmediamanager.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
