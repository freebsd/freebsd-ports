# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	flac123
PORTVERSION=	0.0.11
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/flac-tools/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Command-line player for flac audio files

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libao.so:${PORTSDIR}/audio/libao \
		libpopt.so:${PORTSDIR}/devel/popt

OPTIONS_DEFINE=	DOCS

USES=		gmake
GNU_CONFIGURE=	yes

PORTDOCS=	README.remote
PLIST_FILES=	bin/flac123

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
