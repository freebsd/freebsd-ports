# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	griffith
PORTVERSION=	0.15
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight film collection manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=1.1:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.4:print/py-reportlab@${PY_FLAVOR}

USES=		gettext-runtime gmake gnome python:3.4+ shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	Strit
GL_COMMIT=	a593201179695efe93829d9c9a70962ef29dd109

SHEBANG_FILES=	griffith
USE_GNOME=	pygobject3
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		CHARDET
CHARDET_DESC=		chardet support
CHARDET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR}

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		'/^LANGUAGES=/s|find.*|cd i18n/\&\&ls -d *)|g ; \
		 /^PREFIX/s|?=|=|g ; s|/usr|${PREFIX}|; /ln -s/d; /chmod +x/d; \
		 /^ETCDIR/s|=.*|= $$(PREFIX)/etc|g' ${WRKSRC}/${file}
.endfor
.for f in docs/en/Makefile docs/pl/Makefile docs/pt/Makefile
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s|?=|=|g ; s|/usr|${PREFIX}|; \
		 /^MANDIR/s|=.*|=${STAGEDIR}${MANPREFIX}/man|g' \
		 ${WRKSRC}/${f}
.endfor

post-install:
	${RLN} ${STAGEDIR}${DATADIR}/lib/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
