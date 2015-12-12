# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qlabels
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	deskutils editors
MASTER_SITES=	http://qlabels.p34.net/files/ \
		http://www.sourcefiles.org/Utilities/Printer/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Labels and business cards creating

BROKEN=		unfetchable

USES=		qmake tar:bzip2
USE_QT4=	xml gui corelib uic_build moc_build rcc_build
WRKSRC=		${WRKDIR}/${DISTNAME:C/_/-/}

DESKTOP_ENTRIES=	"qLabels" \
			"${COMMENT}" \
			"" \
			"qlabels" \
			"Office;Qt;" \
			"true"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|/usr|${PREFIX}|g' \
		${WRKSRC}/qlabels.pro \
		${WRKSRC}/lib/templates.cpp \
		${WRKSRC}/lib/papers.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${WRKSRC}/LICENSE \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
