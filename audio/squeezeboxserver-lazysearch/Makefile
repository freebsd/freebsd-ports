# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lazysearch
PORTVERSION=	3.5.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.hickinbottom.com/sc-plugins/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	LazySearch2-7-${PORTVERSION}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin for performing lazy searches

RUN_DEPENDS=	softsqueeze:audio/squeezeboxserver

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/LazySearch2
	${CP} -R ${WRKSRC}/LazySearch2/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/LazySearch2

.include <bsd.port.mk>
