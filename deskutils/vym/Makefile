# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	vym
PORTVERSION=	2.2.4
CATEGORIES=	deskutils
MASTER_SITES=	SF/vym/${PORTVERSION}

MAINTAINER=	lichray@gmail.com
COMMENT=	VYM is a tool to generate and manipulate mind maps

USE_BZIP2=	yes
USE_QT4=	qmake_build uic_build moc_build \
		qt3support network xml dbus svg
QMAKE_ARGS=	PREFIX=${PREFIX} \
		DATADIR=${DATADIR:C,/vym$,,} \
		DOCDIR=${DOCSDIR}
QT_LRELEASE=	${LOCALBASE}/bin/lrelease-qt4

MAKE_JOBS_SAFE=	yes
STRIP_FILES=	bin/vym

DESKTOP_ENTRIES=	"VYM" \
			"Put the things you have got in your mind into a map" \
			"${DATADIR}/icons/vym.png" \
			"vym" \
			"" \
			false

.if !defined(WITHOUT_NLS)
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/INSTALLS += doc/d' ${WRKSRC}/vym.pro
.endif

do-configure:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC} && ${QT_LRELEASE} vym.pro
.endif
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		${QMAKEFLAGS} ${QMAKE_ARGS} vym.pro

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}
.if !defined(WITHOUT_NLS)
	${MKDIR} ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/*.qm ${DATADIR}/lang/
.endif

.include <bsd.port.mk>
