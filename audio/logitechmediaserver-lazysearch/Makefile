# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lazysearch
PORTVERSION=	3.6.5
CATEGORIES=	audio
MASTER_SITES=	http://www.hickinbottom.com/sc-plugins/
PKGNAMEPREFIX=	logitechmediaserver-
DISTNAME=	LazySearch2-7-${PORTVERSION}
DIST_SUBDIR=	logitechmediaserver

MAINTAINER=	mark@tranquillussoftware.co.uk
COMMENT=	Logitech Media Server plugin for performing lazy searches

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LazySearch2/LICENSE

RUN_DEPENDS=	${LOCALBASE}/${SLIMDIR}/slimserver.pl:audio/logitechmediaserver

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	share/logitechmediaserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/LazySearch2
	${CP} -R ${WRKSRC}/LazySearch2/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/LazySearch2

.include <bsd.port.mk>
