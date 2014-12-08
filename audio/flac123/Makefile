# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	flac123
PORTVERSION=	0.0.12
DISTVERSIONSUFFIX=	-release
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/flac-tools/${PORTNAME}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Command-line player for flac audio files

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libao.so:${PORTSDIR}/audio/libao \
		libpopt.so:${PORTSDIR}/devel/popt

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		autoreconf gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README.remote
PLIST_FILES=	bin/flac123

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
