# Created by: che@bein.link
# $FreeBSD$

PORTNAME=	khal
PORTVERSION=	0.7.1
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	CalDAV-based calendar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}icalendar>=3.8.2:devel/py-icalendar@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.2.1:devel/py-urwid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2014.10,1:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.3:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.0:devel/py-tzlocal@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vdirsyncer<0.13:deskutils/py-vdirsyncer@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>0:sysutils/py-pkginfo@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

PLIST_FILES=	share/zsh/site-functions/__khal

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/__khal \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
