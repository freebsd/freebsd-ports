# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gourmet
PORTVERSION=	0.17.4
PORTREVISION=	2
CATEGORIES=	deskutils gnome

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GNOME recipe manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:${PORTSDIR}/devel/py-python-distutils-extra \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:${PORTSDIR}/textproc/py-elib.intl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}poppler>=0:${PORTSDIR}/graphics/py-poppler \
		${PYTHON_PKGNAMEPREFIX}rtf>=0:${PORTSDIR}/print/py-rtf \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:${PORTSDIR}/print/py-reportlab \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:${PORTSDIR}/textproc/py-elib.intl

OPTIONS_DEFINE=		IPYTHON
IPYTHON_DESC=		Interactive shell support
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>0:${PORTSDIR}/devel/ipython

USES=		gettext python:2
USE_GNOME=	intltool pygnome2 pygtk2
USE_PYTHON=	autoplist distutils
PLIST_FILES+=	man/man1/gourmet.1.gz
USE_GITHUB=	yes
GH_ACCOUNT=	thinkle

post-patch:
	@${REINPLACE_CMD} -e "s,'spellcheck',#'spellcheck',g" \
		${WRKSRC}/gourmet/plugin_loader.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/gourmet.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
