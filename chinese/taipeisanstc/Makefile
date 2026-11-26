PORTNAME=	taipeisanstc
DISTVERSION=	Beta
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	https://people.cs.nycu.edu.tw/~lwhsu/ports/distfiles/taipeisanstc/
EXTRACT_ONLY=

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Taipei Sans TC
WWW=		https://sites.google.com/view/jtfoundry/

LICENSE=	OFL11

USES=		fonts

TYPES=	Bold Light Regular
.for type in ${TYPES}
DISTFILES+=	TaipeiSansTC${DISTVERSION}-${type}.ttf
PLIST_FILES+=	${FONTSDIR}/TaipeiSansTC${DISTVERSION}-${type}.ttf
.endfor

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for type in ${TYPES}
	${INSTALL_DATA} ${DISTDIR}/TaipeiSansTC${DISTVERSION}-${type}.ttf ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
