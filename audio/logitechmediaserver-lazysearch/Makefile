PORTNAME=	lazysearch
PORTVERSION=	3.6.7
CATEGORIES=	audio
MASTER_SITES=	http://www.hickinbottom.com/sc-plugins/
PKGNAMEPREFIX=	logitechmediaserver-
DISTNAME=	LazySearch2-7-${PORTVERSION}
DIST_SUBDIR=	logitechmediaserver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logitech Media Server plugin for performing lazy searches
WWW=		https://github.com/hickinbottoms/lazysearch

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LazySearch2/LICENSE

RUN_DEPENDS=	${LOCALBASE}/${SLIMDIR}/slimserver.pl:audio/logitechmediaserver

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SLIMDIR?=	share/logitechmediaserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/LazySearch2
	${CP} -R ${WRKSRC}/LazySearch2/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/LazySearch2

.include <bsd.port.mk>
