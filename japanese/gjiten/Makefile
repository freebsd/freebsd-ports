# Created by: Stephane Lapie <stephane.lapie@darkbsd.org>
# $FreeBSD$

PORTNAME=	gjiten
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	japanese gnome
MASTER_SITES=	http://gjiten.sourceforge.net/

MAINTAINER=	stephane.lapie@darkbsd.org
COMMENT=	Japanese dictionary program for GNOME

OPTIONS_DEFINE=	UTF8 KANJIPAD DOCS NLS
UTF8_DESC=	Use UTF-8 edict dictionaries
KANJIPAD_DESC=	Use Kanjipad

USE_GNOME=	gtk20 gconf2 intltool libglade2 libgnomeui
USES=		gmake libtool pkgconfig
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	gjiten-doc.ja.html
GCONF_SCHEMAS=	gjiten-dicfiles.schemas gjiten.schemas

OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_MAKE_ENV_OFF=	USE_NLS=no

KANJIPAD_RUN_DEPENDS=	${LOCALBASE}/bin/kanjipad:japanese/kanjipad
BUILD_DEPENDS=	${LOCALBASE}/bin/xmlto:textproc/xmlto

DICTIONARIES=	kanjidic edict compdic
GJITEN_DICS=	${DATADIR}/dics/

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUTF8}
EDICT_DIR=	${LOCALBASE}/share/dict/edict-utf-8
EDICT_FILE=	${EDICT_DIR}/edict
RUN_DEPENDS+=	${EDICT_FILE}:japanese/edict-utf-8
.else
EDICT_DIR=	${LOCALBASE}/share/dict/edict
EDICT_FILE=	${EDICT_DIR}/edict
RUN_DEPENDS+=	${EDICT_FILE}:japanese/edict
USES+=		iconv:build
.endif

post-install:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/help/ja/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL} -d ${STAGEDIR}${GJITEN_DICS}
.if ${PORT_OPTIONS:MUTF8}
.for f in ${DICTIONARIES}
	${INSTALL_DATA} ${EDICT_DIR}/${f} ${STAGEDIR}${GJITEN_DICS}
.endfor
.else
.for f in ${DICTIONARIES}
	${ICONV_CMD} -c -f EUC-JP -t UTF-8 ${EDICT_DIR}/${f} > ${STAGEDIR}${GJITEN_DICS}/${f}
.endfor
.endif

.include <bsd.port.mk>
