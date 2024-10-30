PORTNAME=	elffont
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	chinese x11-fonts

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Typeface blending Bopomofo phonetic symbols with "Elvish"
WWW=		https://github.com/justfont/Elffont/

LICENSE=	unknown
LICENSE_NAME=	Elffont
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	justfont

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Elffont-${DISTVERSION}

TYPES=		fern rock

.for type in ${TYPES}
PLIST_FILES+=	${FONTSDIR}/elffont-${type}.otf
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for type in ${TYPES}
	${INSTALL_DATA} ${WRKSRC}/fonts/elffont-${type}.otf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
