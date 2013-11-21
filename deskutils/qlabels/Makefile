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

USES=		qmake
USE_BZIP2=	yes
USE_QT4=	xml gui corelib uic_build moc_build rcc_build
WRKSRC=		${WRKDIR}/${DISTNAME:C/_/-/}

DESKTOP_ENTRIES=	"qLabels" \
			"${COMMENT}" \
			"" \
			"qlabels" \
			"Office;Qt;" \
			"true"

post-patch:
	@${REINPLACE_CMD} 's|/usr|${PREFIX}|g' \
		${WRKSRC}/qlabels.pro \
		${WRKSRC}/lib/templates.cpp \
		${WRKSRC}/lib/papers.cpp

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${WRKSRC}/LICENSE \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
