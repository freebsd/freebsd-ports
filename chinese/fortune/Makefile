# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	fortune
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	fortune-mod-zh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic fortune file in Chinese

RUN_DEPENDS=	autob5:${PORTSDIR}/chinese/autoconvert

PROJECTHOST=	chinese-fortune
NO_BUILD=	yes
USES=		gmake
USE_BZIP2=	yes
SUB_FILES=	pkg-message

.if !exists(/usr/games/fortune) || !exists(/usr/games/strfile)
IGNORE=		needs the FreeBSD games distribution
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/|${PREFIX}/|" \
		-e "s|strfile|/usr/games/strfile|" \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
