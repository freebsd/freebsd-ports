# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcomicbook
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://qcomicbook.linux-projects.net/releases/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Qt-based comic book archive viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar
USE_QT4=	corelib gui linguist_build moc_build qmake_build rcc_build \
		uic_build xml
USES=		cmake pkgconfig

PLIST_FILES=	\
		${DESKTOPDIR:S,^${PREFIX}/,,}/${PORTNAME}.desktop \
		bin/qcomicbook \
		share/pixmaps/qcomicbook.png \
		share/qcomicbook/i18n/qcomicbook_cs_CZ.qm \
		share/qcomicbook/i18n/qcomicbook_de_DE.qm \
		share/qcomicbook/i18n/qcomicbook_en_EN.qm \
		share/qcomicbook/i18n/qcomicbook_es_ES.qm \
		share/qcomicbook/i18n/qcomicbook_it_IT.qm \
		share/qcomicbook/i18n/qcomicbook_fi_FI.qm \
		share/qcomicbook/i18n/qcomicbook_fr_FR.qm \
		share/qcomicbook/i18n/qcomicbook_fr_CA.qm \
		share/qcomicbook/i18n/qcomicbook_ko_KR.qm \
		share/qcomicbook/i18n/qcomicbook_nl_NL.qm \
		share/qcomicbook/i18n/qcomicbook_pl_PL.qm \
		share/qcomicbook/i18n/qcomicbook_pt_BR.qm \
		share/qcomicbook/i18n/qcomicbook_ru_RU.qm \
		share/qcomicbook/i18n/qcomicbook_uk_UA.qm \
		share/qcomicbook/i18n/qcomicbook_zh_CN.qm

PLIST_DIRS=	share/qcomicbook/i18n \
		share/qcomicbook

MAN1=		qcomicbook.1
NO_MANCOMPRESS=	yes

OPTIONS_DEFINE=	7ZIP ACE
OPTIONS_DEFAULT=7ZIP ACE

7ZIP_DESC=	7-Zip (.cb7) comic book archives support
ACE_DESC=	ACE (.cba) comic book archives support

NO_STAGE=	yes
post-patch:
# fix man install directory
	@${REINPLACE_CMD} -E \
		-e 's|share/man|man|' \
		${WRKSRC}/help/CMakeLists.txt
# fix pixmap location
	@${REINPLACE_CMD} -E \
		-e 's|(qcomicbook.png)|${PREFIX}/share/pixmaps/\1|' \
		${WRKSRC}/data/qcomicbook.desktop

.include <bsd.port.options.mk>

# 7-Zip (.cb7) support
.if ${PORT_OPTIONS:M7ZIP}
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

# ACE (.cba) support
.if ${PORT_OPTIONS:MACE}
RUN_DEPENDS+=	unace:${PORTSDIR}/archivers/unace
.endif

.include <bsd.port.mk>
