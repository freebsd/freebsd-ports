# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gourmet
PORTVERSION=	0.17.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://github.com/thinkle/gourmet/archive/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GNOME recipe manager

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distutils-extra>0:${PORTSDIR}/devel/py-distutils-extra \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:${PORTSDIR}/textproc/py-elib.intl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}poppler>=0:${PORTSDIR}/graphics/py-poppler \
		${PYTHON_PKGNAMEPREFIX}rtf>=0:${PORTSDIR}/print/py-rtf \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:${PORTSDIR}/print/py-reportlab \
		${PYTHON_PKGNAMEPREFIX}elib.intl>0:${PORTSDIR}/textproc/py-elib.intl

USES=		gettext
USE_GNOME=	pygnome2 pygnomeextras pygtk2
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PLIST_FILES+=	man/man1/gourmet.1.gz
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${INSTALL_MAN} ${WRKSRC}/gourmet.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
