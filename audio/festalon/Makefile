# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	festalon
PORTVERSION=	0.5.5
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/festalon/ \
		CRITICAL
PKGNAMEPREFIX?=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT?=	Command line player for .nsf and .hes audio files

LICENSE=	GPLv2

LIB_DEPENDS+=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate

USES=		pkgconfig tar:bzip2
USE_AUTOTOOLS=	libtool

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
BROKEN_i386=	does not build on i386 FreeBSD 10.x and later
.endif

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
