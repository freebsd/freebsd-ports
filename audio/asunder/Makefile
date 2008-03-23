# New ports collection makefile for:	asunder
# Date created:				14 September 2007
# Whom:					frase@frase.id.au
#
# $FreeBSD$

PORTNAME=	asunder
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/

MAINTAINER=	frase@frase.id.au
COMMENT=	A lightweight GTK+ CD ripper

LIB_DEPENDS=	cddb.4:${PORTSDIR}/audio/libcddb
RUN_DEPENDS=	${LOCALBASE}/bin/cdparanoia:${PORTSDIR}/audio/cdparanoia

OPTIONS=	LAME "lame support" on \
		OGG "ogg-vorbis support" on \
		FLAC "FLAC support" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

.include <bsd.port.pre.mk>

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_OGG)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/asunder.desktop ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/asunder.png ${DATADIR}/

.include <bsd.port.post.mk>
