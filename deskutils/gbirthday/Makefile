# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gbirthday
PORTVERSION=	0.6.10
CATEGORIES=	deskutils gnome

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Birthday reminder for GNOME2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_TUPLE=	lafrech:gbirthday:7b431aa

OPTIONS_DEFINE=		MYSQL NLS NOTIFY THUNDERBIRD
OPTIONS_SUB=		yes
THUNDERBIRD_DESC=	Thunderbird/Sunbird support
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb
NLS_USES=		gettext
NLS_USE=		GNOME=intltool
NOTIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>0:devel/py-notify
THUNDERBIRD_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

NO_ARCH=	yes
USES=		python:2.7,run
USE_GNOME=	pygtk2
LANGUAGES=	cs da de en es fi fr gl he it pl pt ru sk

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|.mozilla-thunderbird|.thunderbird|g' \
		${WRKSRC}/src/${PORTNAME}/databases/lightning.py
	@${REINPLACE_CMD} -e 's|@VER@|${PORTVERSION}|g' \
		${WRKSRC}/src/${PORTNAME}/__init__.py
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/src/gb
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|_Comment|Comment|' ${WRKSRC}/${PORTNAME}.desktop.in
.endif

do-build:
.if ${PORT_OPTIONS:MNLS}
	@-intltool-merge -d ${WRKSRC}/po ${WRKSRC}/${PORTNAME}.desktop.in \
		${WRKSRC}/${PORTNAME}.desktop
	@(for lang in ${LANGUAGES} ; do \
		cd ${WRKSRC}/po ; \
		${LOCALBASE}/bin/msgfmt $$lang.po -o $$lang.mo ; \
	done)
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/pics/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_SCRIPT} ${WRKSRC}/src/gb ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/databases
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/pics
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/*.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/databases/*.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/databases
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/pics/*.png ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/pics
.if ${PORT_OPTIONS:MNLS}
	@(for lang in ${LANGUAGES} ; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/$$lang/LC_MESSAGES ; \
		${INSTALL_DATA} ${WRKSRC}/po/$$lang.mo \
		${STAGEDIR}${PREFIX}/share/locale/$$lang/LC_MESSAGES/${PORTNAME}.mo ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
.else
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop.in \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
.endif

.include <bsd.port.mk>
