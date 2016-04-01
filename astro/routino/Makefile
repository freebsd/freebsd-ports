# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	routino
PORTVERSION=	3.1.1
CATEGORIES=	astro
MASTER_SITES=	http://www.routino.org/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Router for OpenStreetMap Data

LICENSE=	AGPLv3

OPTIONS_DEFINE=	DOCS
USES=		gmake perl5 tar:tgz
#USE_GCC=	any
USE_LDCONFIG=	yes
#MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} 's|doc/routino|share/doc/routino|' \
		${WRKSRC}/Makefile.conf
	${REINPLACE_CMD} 's|gcc|${CC}|' \
		${WRKSRC}/Makefile.conf
post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/web && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name Makefile")
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/bin/*

.include <bsd.port.mk>
