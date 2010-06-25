# New ports collection makefile for: zh-fortune
# Date created:                17 Dec 2009
# Whom:                        Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fortune
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	zh-
DISTNAME=	fortune-mod-zh-${PORTVERSION}

MAINTAINER=	jupengfei@gmail.com
COMMENT=	A very classic fortune file in Chinese

RUN_DEPENDS=	autob5:${PORTSDIR}/chinese/autoconvert

PROJECTHOST=	chinese-fortune
NO_BUILD=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
SUB_FILES=	pkg-message

.if !exists(/usr/games/fortune) || !exists(/usr/games/strfile)
IGNORE=		needs the FreeBSD games distribution
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/|${PREFIX}/|" \
		-e "s|strfile|/usr/games/strfile|" \
		${WRKSRC}/src/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
