# New ports collection makefile for:	qcomicbook
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcomicbook
PORTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	http://qcomicbook.linux-projects.net/releases/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	QT-based comic book archive viewer

BUILD_DEPENDS=	lrelease-qt4:${PORTSDIR}/devel/qt4-linguist
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build qmake_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	\
		${DESKTOPDIR:S,^${PREFIX}/,,}/${PORTNAME}.desktop \
		bin/qcomicbook \
		share/pixmaps/qcomicbook.png \
		share/qcomicbook/i18n/qcomicbook_es_ES.qm \
		share/qcomicbook/i18n/qcomicbook_it_IT.qm \
		share/qcomicbook/i18n/qcomicbook_fi_FI.qm \
		share/qcomicbook/i18n/qcomicbook_fr_FR.qm \
		share/qcomicbook/i18n/qcomicbook_fr_CA.qm \
		share/qcomicbook/i18n/qcomicbook_pl_PL.qm \
		share/qcomicbook/i18n/qcomicbook_pt_BR.qm \
		share/qcomicbook/i18n/qcomicbook_uk_UA.qm
#
PLIST_DIRS=	share/qcomicbook/i18n \
		share/qcomicbook

MAN1=		qcomicbook.1
NO_MANCOMPRESS=	yes

OPTIONS=	7ZIP "Enable support for 7-Zip (.cb7) comic book archives" on \
		ACE "Enable support for ACE (.cba) comic book archives" on

post-patch:
# fix man install directory
	@${REINPLACE_CMD} -E \
		-e 's|share/man|man|' \
		${WRKSRC}/help/CMakeLists.txt
# fix pixmap location
	@${REINPLACE_CMD} -E \
		-e 's|(qcomicbook.png)|${PREFIX}/share/pixmaps/\1|' \
		${WRKSRC}/data/qcomicbook.desktop

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
CPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not link on 6.X
.endif

# 7-Zip (.cb7) support
.if !defined(WITHOUT_7ZIP)
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

# ACE (.cba) support
.if !defined(WITHOUT_ACE)
RUN_DEPENDS+=	unace:${PORTSDIR}/archivers/unace
.endif

.include <bsd.port.post.mk>
