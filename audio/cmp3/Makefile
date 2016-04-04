# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmp3
PORTVERSION=	2.0.p6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.0-pre6
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses based frontend to mpg123

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	mpg123:audio/mpg123

WRKSRC=		${WRKDIR}/${PORTNAME}-kenrevs

USES=		gmake ncurses
GNU_CONFIGURE=	yes
MAKE_ARGS=	install_directory=${STAGEDIR}${PREFIX}/bin

PORTDOCS=	README sample.cmp3rc
PLIST_FILES=	bin/cmp3 bin/rnmp3

OPTIONS_DEFINE=	DOCS VORBIS
OPTIONS_DEFAULT=	VORBIS

VORBIS_RUN_DEPENDS=	ogg123:audio/vorbis-tools

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
