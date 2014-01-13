# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gbirthday
PORTVERSION=	0.6.7
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Birthday reminder for Evolution and some others

LICENSE=	GPLv2

OPTIONS_DEFINE=	EVO THUNDER MYSQL NOTIFY
OPTIONS_DEFAULT=EVO
EVO_DESC=	Evolution support
THUNDER_DESC=	Thunderbird/Sunbird support

USE_XZ=		yes
USE_PYTHON_RUN=	2
USE_GNOME=	pygtk2 desktopfileutils

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
USE_GNOME+=	intltool
LANGUAGES=	de en es fr gl it pl pt ru sk
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEVO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb
USE_GNOME+=	evolutiondataserver
.endif

.if ${PORT_OPTIONS:MTHUNDER}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}notify>0:${PORTSDIR}/devel/py-notify
.endif

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
	${INSTALL_DATA} ${WRKSRC}/pics/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${INSTALL_SCRIPT} ${WRKSRC}/src/gb ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/databases
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/pics
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/*.py ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/databases/*.py ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/databases
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/pics/*.png ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/pics
.if ${PORT_OPTIONS:MNLS}
	@(for lang in ${LANGUAGES} ; do \
		${MKDIR} ${PREFIX}/share/locale/$$lang/LC_MESSAGES ; \
		${INSTALL_DATA} ${WRKSRC}/po/$$lang.mo \
		${PREFIX}/share/locale/$$lang/LC_MESSAGES/${PORTNAME}.mo ; \
	done)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
.else
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop.in \
		${PREFIX}/share/applications/${PORTNAME}.desktop
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
