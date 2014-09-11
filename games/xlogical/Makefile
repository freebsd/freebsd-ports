# Created by: Aaron Baugher
# $FreeBSD$

PORTNAME=	xlogical
PORTVERSION=	1.0p8
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://changeling.ixionstudios.com/xlogical/downloads/ \
		http://freebsd.portsreview.info/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-/}

MAINTAINER=	aaron@baugher.biz
COMMENT=	Remake of the classic puzzle game Logical

LICENSE=	GPLv2

USES=		gmake tar:bzip2 dos2unix
USE_AUTOTOOLS=	aclocal automake autoconf
AUTOMAKE_ARGS=	--add-missing
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${CHMOD} 755 ${WRKSRC}/missing
	@${RM} ${WRKSRC}/LICENSE

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/[A-Z][A-Z]* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
