PORTNAME=	auralquiz
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple music quiz game using your own music files
WWW=		https://jancoding.wordpress.com/auralquiz/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		compiler:c++11-lang gl kde:6 qmake qt:6
USE_GL=		gl
USE_KDE=	phonon
USE_QT=		base

PORTDOCS=	CHANGELOG README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/Auralquiz.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
