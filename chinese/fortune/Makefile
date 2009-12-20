# New ports collection makefile for: zh-fortune
# Date created:                17 Dec 2009
# Whom:                        Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fortune
PORTVERSION=	1.2.2
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	zh-
DISTNAME=	fortune-mod-zh-${PORTVERSION}

MAINTAINER=	jupengfei@gmail.com
COMMENT=	A very classic fortune file in Chinese

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		autob5:${PORTSDIR}/chinese/autoconvert

PROJECTHOST=	chinese-fortune
NO_BUILD=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

.if !exists (/usr/games/fortune) || !exists(/usr/games/strfile)
IGNORE=		needs the FreeBSD games distribution
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
		-e "s|/usr/bin/fortune|/usr/games/fortune|" \
		${WRKSRC}/src/fortune-zh
	@${REINPLACE_CMD} -e "s|/usr/|${PREFIX}/|" \
		-e "s|strfile|/usr/games/strfile|" \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
