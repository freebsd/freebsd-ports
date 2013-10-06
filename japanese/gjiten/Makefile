# Created by: Stephane Lapie <stephane.lapie@darkbsd.org>
# $FreeBSD$

PORTNAME=	gjiten
PORTVERSION=	2.6
CATEGORIES=	japanese gnome
MASTER_SITES=	http://gjiten.sourceforge.net/

MAINTAINER=	stephane.lapie@darkbsd.org
COMMENT=	Japanese dictionary program for GNOME

OPTIONS_DEFINE=	UTF8 KANJIPAD DOCS NLS
UTF8_DESC=	Use UTF-8 edict dictionaries
KANJIPAD_DESC=	Use Kanjipad

USE_GNOME=	gtk20 gconf2 libglade2 libgnomeui
USES=		gmake pkgconfig
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	gjiten-doc.ja.html
MAN1=		gjiten.1
GCONF_SCHEMAS=	gjiten-dicfiles.schemas gjiten.schemas

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
MAKE_ENV+=	USE_NLS=no
.endif

.if ${PORT_OPTIONS:MUTF8}
EDICT_DIR=	${LOCALBASE}/share/dict/edict-utf-8
EDICT_FILE=	${EDICT_DIR}/edict
RUN_DEPENDS+=	${EDICT_FILE}:${PORTSDIR}/japanese/edict-utf-8
.else
EDICT_DIR=	${LOCALBASE}/share/dict/edict
EDICT_FILE=	${EDICT_DIR}/edict
RUN_DEPENDS+=	${EDICT_FILE}:${PORTSDIR}/japanese/edict
USES+=		iconv:build
.endif

DICTIONARIES=	kanjidic edict compdic
GJITEN_DICS=	${DATADIR}/dics/

.if ${PORT_OPTIONS:MKANJIPAD}
RUN_DEPENDS+=	${LOCALBASE}/bin/kanjipad:${PORTSDIR}/japanese/kanjipad
.endif

BUILD_DEPENDS+=	${LOCALBASE}/bin/xmlto:${PORTSDIR}/textproc/xmlto

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/help/ja/${f} ${DOCSDIR}
.endfor
.endif
	@${INSTALL} -d ${GJITEN_DICS}
.if ${PORT_OPTIONS:MUTF8}
.for f in ${DICTIONARIES}
	${INSTALL_DATA} ${EDICT_DIR}/${f} ${GJITEN_DICS}
.endfor
.else
.for f in ${DICTIONARIES}
	${ICONV_CMD} -c -f EUC-JP -t UTF-8 ${EDICT_DIR}/${f} > ${GJITEN_DICS}/${f}
.endfor
.endif
	-@update-desktop-database

.include <bsd.port.mk>
