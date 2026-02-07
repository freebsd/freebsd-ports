PORTNAME=	baekmukfonts
PORTVERSION=	2.2
PORTREVISION=	4
CATEGORIES=	korean x11-fonts
MASTER_SITES=	https://kldp.net/baekmuk/release/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-ttf
DISTNAME=	865-${FONTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Baekmuk family Korean TrueType Fonts
WWW=		https://kldp.net/baekmuk/

LICENSE=	Baekmuk
LICENSE_NAME=	Baekmuk
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts

FONTNAME=	baekmuk
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/^865-//}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT COPYRIGHT.ks README \
	    contrib/hconfig.ps ttf/*.ttf ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>
