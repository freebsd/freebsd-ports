# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmp3
PORTVERSION=	2.0.p6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.0-pre6
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	An ncurses based frontend to mpg123

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-kenrevs

USES=		gmake
NO_STAGE=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	README sample.cmp3rc
PLIST_FILES=	bin/cmp3 bin/rnmp3

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
