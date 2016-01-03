# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	circuslinux
PORTVERSION=	1.0.3
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/circus-linux/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Circus Linux!" is a clone of the Atari 2600 game "Circus Atari"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_SDL=	image mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=""

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
