PORTNAME=	auralquiz
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple music quiz game using your own music files
WWW=		https://jancoding.wordpress.com/auralquiz/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		compiler:c++11-lang gl kde:5 qmake qt:5
USE_GL=		gl
USE_KDE=	phonon
USE_QT=		core gui widgets qmake:build buildtools:build

PORTDOCS=	CHANGELOG README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|; \
		s|%%MAN6PREFIX%%|${MAN6PREFIX}|' \
		${WRKSRC}/Auralquiz.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
