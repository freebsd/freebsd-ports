# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qorganizer
PORTVERSION=	3.1
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	qOrganizer-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	General organizer that includes calendar with jurnal and schedule

USES=		qmake
USE_QT4=	gui network moc_build rcc_build sql
WRKSRC=		${WRKDIR}/qOrganizer/src

PLIST_FILES=	bin/qOrganizer share/pixmaps/qOrganizer.png
PORTDOCS=	CHANGELOG.txt COPYING

DESKTOP_ENTRIES=	"qOrganizer" \
			"${COMMENT}" \
			"qOrganizer" \
			"qOrganizer" \
			"Qt;KDE;Office;" \
			"true"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qOrganizer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../qOrganizer.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
