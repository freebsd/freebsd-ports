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

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	autob5:chinese/autoconvert
BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile
STRFILE=	${LOCALBASE}/bin/fortune_strfile

PROJECTHOST=	chinese-fortune
NO_BUILD=	yes
USES=		tar:bzip2 gmake
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/|${PREFIX}/|" \
		-e "s|strfile|${STRFILE}|" \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
