# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	amoebax
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.emma-soft.com/games/amoebax/download/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cute and addictive Puyo Puyo like game

LICENSE=	GPLv2 FAL
LICENSE_COMB=	dual
LICENSE_NAME_FAL=	Free Art License, version 1.2
LICENSE_FILE_FAL=	${WRKSRC}/COPYING.LAL
LICENSE_PERMS_FAL=	${_LICENSE_PERMS_DEFAULT}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image

MAN6=		amoebax.6

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|datarootdir|datadir|' ${WRKSRC}/data/Makefile.in
	@${FIND} ${WRKSRC}/ -name Makefile.in|${XARGS}\
		${REINPLACE_CMD} -e '/^pkgdatadir =/s|=.*|= ${DATADIR}|'

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
