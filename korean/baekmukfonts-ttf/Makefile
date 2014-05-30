# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	baekmukfonts
PORTVERSION=	2.2
CATEGORIES=	korean
MASTER_SITES=	http://kldp.net/frs/download.php/1429/
PKGNAMESUFFIX=	-ttf
DISTNAME=	${FONTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Baekmuk family Korean TrueType Fonts

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

NO_BUILD=	yes

FONTNAME=	baekmuk
FONTSDIR=	lib/X11/fonts/${FONTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT COPYRIGHT.ks README \
		contrib/hconfig.ps ttf/*.ttf ttf/fonts.dir \
		${STAGEDIR}${PREFIX}/${FONTSDIR})
	${INSTALL_DATA} ${WRKSRC}/ttf/fonts.scale.xtt \
		${STAGEDIR}${PREFIX}/${FONTSDIR}/fonts.scale

.include <bsd.port.mk>
