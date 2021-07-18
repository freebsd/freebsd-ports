# Created by: Ashish SHUKLA <ashish@FreeBSD.org>

PORTNAME=	mcomix
PORTVERSION=	1.2.1g20210526
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	GTK3 comic book viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=5.2.0:graphics/py-pillow@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gnome python:3.8+ shebangfix
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	flavors
USE_GITHUB=	yes
GH_ACCOUNT=	multiSnow
GH_PROJECT=	mcomix3
GH_TAGNAME=	9eb4fc7
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	mcomix/mcomixstarter.py

OPTIONS_DEFINE=	RAR
OPTIONS_DEFAULT=RAR

RAR_DESC=	RAR (.cbr) comic book archives support
RAR_RUN_DEPENDS=${LOCALBASE}/lib/libunrar.so.6:archivers/libunrar6

post-patch:
	@${REINPLACE_CMD} "s|^VERSION =.*|VERSION = '${PORTVERSION}'|" \
		${WRKSRC}/mcomix/mcomix/constants.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/mcomix
	(cd ${WRKSRC}/mcomix/mcomix && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/mcomix)
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/mcomix
	${INSTALL} ${WRKSRC}/mcomix/mcomixstarter.py ${STAGEDIR}/${PREFIX}/bin/mcomix

.include <bsd.port.mk>
