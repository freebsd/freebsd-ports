# Created by: che@bein.link
# $FreeBSD$

PORTNAME=	khal
PORTVERSION=	0.7.0
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	CalDAV-based calendar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.2:${PORTSDIR}/devel/py-click \
		${PYTHON_PKGNAMEPREFIX}icalendar>=3.8.2:${PORTSDIR}/devel/py-icalendar \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.2.1:${PORTSDIR}/devel/py-urwid \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}pytz>=2014.10:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.3:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.0:${PORTSDIR}/devel/py-tzlocal \
		${PYTHON_PKGNAMEPREFIX}vdirsyncer>=0.4.3:${PORTSDIR}/deskutils/py-vdirsyncer \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}pkginfo>0:${PORTSDIR}/sysutils/py-pkginfo

USES=		python
USE_PYTHON=	autoplist distutils

PLIST_FILES=	share/zsh/site-functions/__khal

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/__khal \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
