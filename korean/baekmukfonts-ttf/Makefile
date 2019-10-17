# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	baekmukfonts
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	korean
MASTER_SITES=	https://kldp.net/baekmuk/release/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-ttf
DISTNAME=	865-${FONTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Baekmuk family Korean TrueType Fonts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		fonts

FONTNAME=	baekmuk
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/^865-//}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT COPYRIGHT.ks README \
		contrib/hconfig.ps ttf/*.ttf \
		${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
