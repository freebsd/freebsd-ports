# Created by: sada
# $FreeBSD$

PORTNAME=	mikachan-ttfonts
PORTVERSION=	9.1
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://mikachan.sourceforge.jp/
DISTNAME=	ver${PORTVERSION}
EXTRACT_SUFX=	.lzh

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Handwritten Japanese TrueType fonts by Mika-chan

EXTRACT_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USES=		fonts
NO_CDROM=	Do not sell distfile
EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	pq
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/mika.ttf
DIST_SUBDIR=	${PORTNAME}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV=	FONTSDIR=${FONTSDIR}

FONTNAME=	TrueType

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} \
		${WRKDIR}/mika.ttf ${FILESDIR}/fonts.dir.mika \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
