# New ports collection makefile for:	qlabels
# Date created:		12 Jul 2007
# Whom:			Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qlabels
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	deskutils editors
MASTER_SITES=	http://qlabels.p34.net/files/ \
		http://www.sourcefiles.org/Utilities/Printer/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A labels and business cards creating and printing software

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	xml gui corelib qmake_build uic_build moc_build rcc_build
WRKSRC=		${WRKDIR}/${DISTNAME:C/_/-/}

DESKTOP_ENTRIES=	"qlabels" \
			"A labels and business cards creating and printing software" \
			"" \
			"qlabels" \
			"Application;Office;" \
			"false"

post-patch:
	@${REINPLACE_CMD} 's|/usr|${PREFIX}|g' \
		${WRKSRC}/qlabels.pro \
		${WRKSRC}/lib/templates.cpp \
		${WRKSRC}/lib/papers.cpp

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix qlabels.pro

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in Changelog LICENSE
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
