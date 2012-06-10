# $FreeBSD$

PORTNAME=	anki
PORTVERSION=	1.2.11
PORTREVISION?=	2
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://ankisrs.net/download/mirror/
EXTRACT_SUFX=	.tgz

USE_PYTHON=	-2.7
USE_GETTEXT=	yes
USE_PYDISTUTILS=	easy_install

.if !defined(PKGNAMEPREFIX)
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=4.4:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.4:${PORTSDIR}/x11-toolkits/py-qt4-gui
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}sip>=4.6:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.0:${PORTSDIR}/math/py-matplotlib \

USE_QT4=	corelib gui
PYDISTUTILS_PKGNAME=	ankiqt

PORT_VERBS=	ankiqt
DESKTOP_ENTRIES=	"${PORTNAME}" \
		"${COMMENT}" \
		"" \
		"anki" \
		"Education;Languages;Qt;" \
		false
.else
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.0:${PORTSDIR}/math/py-matplotlib

PLIST=		${PKGDIR}/pkg-plist.py-anki
WRKSRC=		${WRKDIR}/${DISTNAME}/lib${PORTNAME}
.endif

post-patch:
.if !defined(PKGNAMEPREFIX)
	@${REINPLACE_CMD} -e '/req/d' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
