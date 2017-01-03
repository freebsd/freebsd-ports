# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	festalon
PORTVERSION=	0.5.5
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/festalon/ \
		LOCAL/ehaupt
PKGNAMEPREFIX?=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT?=	Command line player for .nsf and .hes audio files

LICENSE=	GPLv2

BROKEN_i386=	does not build on i386 FreeBSD 10.x and later

LIB_DEPENDS+=	libsamplerate.so:audio/libsamplerate

USES+=		libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

.if ${PKGNAMEPREFIX} == ""

USE_SDL=	yes

PLIST_FILES=	bin/festalon
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
