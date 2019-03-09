# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	garden-of-coloured-lights
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/garden/garden/${PORTVERSION}/
DISTNAME=	garden-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Old school 2D vertical shoot-em-up with some innovative elements

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liballeg.so:devel/allegro

GNU_CONFIGURE=	yes
USES=		desktop-file-utils localbase
INSTALLS_ICONS=	yes

DATADIR=	${PREFIX}/share/garden

PORTDOCS=	AUTHORS ChangeLog NEWS README
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
