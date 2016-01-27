# Created by: Aaron Baugher
# $FreeBSD$

PORTNAME=	xlogical
PORTVERSION=	1.0p8
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://changeling.ixionstudios.com/xlogical/downloads/ \
		http://freebsd.portsreview.info/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-/}

MAINTAINER=	aaron@baugher.biz
COMMENT=	Remake of the classic puzzle game Logical

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir="${PREFIX}/var"
USES=		autoreconf dos2unix gmake tar:bzip2
USE_SDL=	sdl image mixer

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CHMOD} 755 ${WRKSRC}/missing
	@${RM} ${WRKSRC}/LICENSE

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
