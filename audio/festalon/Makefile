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

LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000000
BROKEN=		does not build on FreeBSD 10.x and later
.endif

.if ${PKGNAMEPREFIX} == ""

USE_SDL=	yes

PLIST_FILES=	bin/festalon
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.endif

.include <bsd.port.mk>
