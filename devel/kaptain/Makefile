# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaptain
PORTVERSION=	0.73
CATEGORIES=	devel
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for building/running Qt GUIs for command line programs

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		qmake
USE_QT4=	qt3support moc_build

INFO=		kaptain
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/kaptain \
		man/man1/kaptain.1.gz

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^QMAKE_|#QMAKE_|' ${WRKSRC}/kaptain.pro
	@${FIND} ${WRKSRC}/examples -maxdepth 1 -type f | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|/usr/bin/kaptain|${SETENV} kaptain|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kaptain ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/kaptain.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/kaptain.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc \
		&& ${INSTALL_DATA} *.gif *.html *.png *.tgz ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples \
		&& ${INSTALL_DATA} *.kaptn *.tgz ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
