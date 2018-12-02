# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qorganizer
PORTVERSION=	3.1
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	qOrganizer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General organizer that includes calendar with jurnal and schedule

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_QT=		corelib gui network moc_build rcc_build sql
WRKSRC=		${WRKDIR}/qOrganizer/src

PLIST_FILES=	bin/qOrganizer share/pixmaps/qOrganizer.png
PORTDOCS=	CHANGELOG.txt COPYING

DESKTOP_ENTRIES="qOrganizer" \
		"${COMMENT}" \
		"qOrganizer" \
		"qOrganizer" \
		"Qt;KDE;Office;" \
		true

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qOrganizer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../qOrganizer.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
