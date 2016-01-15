# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaptain
PORTVERSION=	0.73
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for building/running Qt GUIs for command line programs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake tar:tgz
USE_QT4=	qt3support moc_build

INFO=		kaptain
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/kaptain \
		man/man1/kaptain.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc \
		&& ${INSTALL_DATA} *.gif *.html *.png *.tgz ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples \
		&& ${INSTALL_DATA} *.kaptn *.tgz ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
