PORTNAME=	taipeisanstc
DISTVERSION=	Beta
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	https://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/taipeisanstc/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Taipei Sans TC

LICENSE=	OFL11

USES=		fonts

TYPES=	Bold Light Regular
.for type in ${TYPES}
DISTFILES+=	TaipeiSansTC${DISTVERSION}-${type}.ttf
PLIST_FILES+=	${FONTSDIR}/TaipeiSansTC${DISTVERSION}-${type}.ttf
.endfor

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	-a
EXTRACT_AFTER_ARGS=	.

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for type in ${TYPES}
	${INSTALL_DATA} ${WRKSRC}/TaipeiSansTC${DISTVERSION}-${type}.ttf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
