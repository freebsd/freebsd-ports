# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmp3
PORTVERSION=	2.0.p6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.0-pre6
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Ncurses based frontend to mpg123

OPTIONS_DEFINE=	DOCS VORBIS
OPTIONS_DEFAULT=	VORBIS

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-kenrevs

USES=		gmake ncurses
GNU_CONFIGURE=	yes
USE_GCC=	any
MAKE_ARGS=	install_directory=${STAGEDIR}${PREFIX}/bin

PORTDOCS=	README sample.cmp3rc
PLIST_FILES=	bin/cmp3 bin/rnmp3

VORBIS_RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
