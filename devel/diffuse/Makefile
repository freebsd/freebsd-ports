# Ports collection makefile for:	diffuse
# Date created:		2009-02-22
# Whom:			Marco Broeder <marco.broeder@gmx.eu>
#
# $FreeBSD$
#

PORTNAME=	diffuse
PORTVERSION=	0.4.6
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	A graphical N-way diff and merge tool written in python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_BUILD=	yes

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_BZIP2=	yes

MAN1=		diffuse.1

OPTIONS=	MENU	"Install a desktop menu entry"	on \
		NLS	"Install translations (work in progress)"	on

.include <bsd.port.options.mk>

.ifndef (NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING ChangeLog ChangeLog_ru README README_ru
.endif

.ifndef (NOPORTDATA)
PORTDATA=	syntax
.endif

.ifdef (WITH_MENU)
PLIST_SUB+=	MENU=""
USE_GNOME+=	desktopfileutils
.else
PLIST_SUB+=	MENU="@comment "
.endif

.ifndef (WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
TRANSLATIONS=	de es it ja ko ru zh_CN
MANLANG=	"" it ru
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.ifndef (NOPORTDATA)
	${REINPLACE_CMD} -e 's|../usr|${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
.else
	${REINPLACE_CMD} -e 's|import ../usr|\#(Disabled by NOPORTDATA !) \
		import ${PREFIX}|g; s|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
.endif

	${REINPLACE_CMD} -e 's|../../etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/usr/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/${PORTNAME} \
		${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}rc ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/*.1 \
		${MANPREFIX}/man/man1/

post-install:
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.ifndef (NOPORTDATA)
	${MKDIR} ${DATADIR}/syntax
	(cd ${WRKSRC}/src/usr/share/${PORTNAME} && \
		${COPYTREE_SHARE} \* ${DATADIR})
.endif

.ifndef (WITHOUT_NLS)
	for x in ${TRANSLATIONS}; do \
		${MKDIR} ${WRKSRC}/translations/$${x}; \
		${LOCALBASE}/bin/msgfmt -c ${WRKSRC}/translations/$${x}.po \
			-o ${WRKSRC}/translations/$${x}/${PORTNAME}.mo; \
		${INSTALL_DATA} ${WRKSRC}/translations/$${x}/*.mo \
			${PREFIX}/share/locale/$${x}/LC_MESSAGES/; \
	done
	for y in ${MANLANG}; do \
		${MKDIR} ${MANPREFIX}/man/$${y}/man1; \
		${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/$${y}/man1/*.1 \
			${MANPREFIX}/man/$${y}/man1/; \
	done
.endif

.ifdef (WITH_MENU)
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/pixmaps/${PORTNAME}.png \
		${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/*.desktop \
		${DESKTOPDIR}
	${LOCALBASE}/bin/update-desktop-database -q
.endif

.include <bsd.port.mk>
