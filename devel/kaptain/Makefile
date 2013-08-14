# Created by: Alan Eldridge <alane@freebsd.org>
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

USE_QT4=	qt3support moc_build qmake_build

MAN1=		kaptain.1
INFO=		kaptain
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/kaptain

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^QMAKE_|#QMAKE_|' ${WRKSRC}/kaptain.pro
	@${FIND} ${WRKSRC}/examples -maxdepth 1 -type f | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|/usr/bin/kaptain|${SETENV} kaptain|'

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} kaptain ${PREFIX}/bin)
	(cd ${WRKSRC}/man \
		&& ${INSTALL_MAN} kaptain.1 ${MANPREFIX}/man/man1)
	(cd ${WRKSRC}/doc \
		&& ${INSTALL_DATA} kaptain.info ${PREFIX}/${INFO_PATH})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} \
		&& ${INSTALL_DATA} README ${DOCSDIR})
	(cd ${WRKSRC}/doc \
		&& ${INSTALL_DATA} *.gif *.html *.png *.tgz ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples \
		&& ${INSTALL_DATA} *.kaptn *.tgz ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
