# New ports collection makefile for:	gbirthday
# Date created:				01 January 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	gbirthday
PORTVERSION=	0.5.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A birthday reminder for Evolution and some others

OPTIONS=	EVO	"Evolution support"	on \
		THUNDER	"Thunderbird/Sunbird support"	off \
		MYSQL	"MySQL database support"	off

NO_WRKSUBDIR=	yes
USE_PYTHON_RUN=	yes
USE_GNOME=	pygtk2 desktopfileutils

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
USE_GNOME+=	intltool
LANGUAGES=	de en es fr gl it pl pt ru sk
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EVO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
USE_GNOME+=	evolutiondataserver
.endif

.if defined(WITH_THUNDER)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/${PORTNAME}|${DATADIR}|g ;  \
		s|/usr/share/pixmaps|${PREFIX}/share/pixmaps|g ; \
		s|.mozilla-thunderbird|.thunderbird|g' \
		${WRKSRC}/src/${PORTNAME}.py ${WRKSRC}/gbirthday.desktop.in
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|_Comment|Comment|' ${WRKSRC}/gbirthday.desktop.in
.endif

do-build:
.if !defined(WITHOUT_NLS)
	@-intltool-merge -d ${WRKSRC}/po ${WRKSRC}/gbirthday.desktop.in \
		${WRKSRC}/gbirthday.desktop
	@(for lang in ${LANGUAGES} ; do \
		cd ${WRKSRC}/po ; \
		${LOCALBASE}/bin/msgfmt $$lang.po -o $$lang.mo ; \
	done)
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${PREFIX}/share/pixmaps/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/pics/* ${PREFIX}/share/pixmaps/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/${PORTNAME}.py ${DATADIR}
	${LN} -fs ${DATADIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/applications
.if !defined(WITHOUT_NLS)
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

.include <bsd.port.post.mk>
