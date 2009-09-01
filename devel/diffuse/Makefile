# Ports collection makefile for:	diffuse
# Date created:		2009-02-22
# Whom:			Marco Broeder <marco.broeder@gmx.eu>
#
# $FreeBSD$
#

PORTNAME=	diffuse
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	A graphical N-way diff and merge tool written in python

NO_BUILD=	yes

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_BZIP2=	yes

MAN1=		diffuse.1

OPTIONS=	MENU	"Add desktop menu (needs desktop-file-utils)"	on \
		OMF	"Install OMF manual (needs scrollkeeper)"	on \
		NLS	"Install some translations (work in progress)"	on

.include <bsd.port.options.mk>

.ifndef (NOPORTDOCS)
DOCS=		AUTHORS COPYING ChangeLog README
.endif

.ifdef (WITH_MENU)
PLIST_SUB+=	MENU=""
RUN_DEPENDS+=	update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
INSTALLS_ICONS=	yes
.else
PLIST_SUB+=	MENU="@comment "
.endif

.ifdef (WITH_OMF)
PLIST_SUB+=	OMF=""
RUN_DEPENDS+=	scrollkeeper-update:${PORTSDIR}/textproc/scrollkeeper
INSTALLS_OMF=	yes
.else
PLIST_SUB+=	OMF="@comment "
.endif

.ifndef (WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
TRANSLATIONS=	de
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|../usr|${PREFIX}|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
	${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' \
		${WRKSRC}/src/etc/${PORTNAME}rc
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/usr/share/omf/${PORTNAME}/${PORTNAME}-C.omf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/usr/bin/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/etc/${PORTNAME}rc ${PREFIX}/etc/

post-install:
	${MKDIR} ${DATADIR}/syntax
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/${PORTNAME}/syntax/*.syntax \
		${DATADIR}/syntax/
	${INSTALL_MAN} ${WRKSRC}/src/usr/share/man/man1/*.1 \
		${MANPREFIX}/man/man1/

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for n in ${DOCS}; do \
		${INSTALL_MAN} ${WRKSRC}/$${n} ${DOCSDIR}; \
	done
.endif

.ifndef (WITHOUT_NLS)
	for x in ${TRANSLATIONS}; do \
		${MKDIR} ${PREFIX}/share/locale/$${x}/LC_MESSAGES; \
		${MKDIR} ${WRKSRC}/translations/$${x}; \
		${PREFIX}/bin/msgfmt -c -v ${WRKSRC}/translations/$${x}.po \
			-o ${WRKSRC}/translations/$${x}/${PORTNAME}.mo; \
		${INSTALL_DATA} ${WRKSRC}/translations/$${x}/*.mo \
			${PREFIX}/share/locale/$${x}/LC_MESSAGES/; \
	done
.endif

.ifdef (WITH_OMF)
	${MKDIR} ${PREFIX}/share/gnome/help/${PORTNAME}/C
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/gnome/help/${PORTNAME}/C/*.xml \
		${PREFIX}/share/gnome/help/${PORTNAME}/C/
	${MKDIR} ${PREFIX}/share/omf/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/omf/${PORTNAME}/*.omf \
		${PREFIX}/share/omf/${PORTNAME}/
	${PREFIX}/bin/scrollkeeper-update -q
.endif

.ifdef (WITH_MENU)
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/pixmaps/${PORTNAME}.png \
		${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/usr/share/applications/*.desktop \
		${DESKTOPDIR}
	${PREFIX}/bin/update-desktop-database
.endif

.include <bsd.port.mk>
