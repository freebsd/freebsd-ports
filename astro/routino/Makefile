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
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} 's|doc/routino|share/doc/routino|' \
		${WRKSRC}/Makefile.conf
	${REINPLACE_CMD} 's|gcc|${CC}|' \
		${WRKSRC}/Makefile.conf

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/web && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name Makefile")
	${CHMOD} 0644 ${STAGEDIR}${PREFIX}/lib/lib*
	${CHMOD} 0755 ${STAGEDIR}${PREFIX}/bin/*
	${CHMOD} 0755 ${STAGEDIR}${WWWDIR}/bin/*
	${RM} ${STAGEDIR}${PREFIX}/lib/libroutino*.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libroutino*.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/bin/*
.for f in routino.so.0.0.0 routino-slim.so.0.0.0
	${LN} -sf lib${f} ${STAGEDIR}${PREFIX}/lib/lib${f:R:R}
	${LN} -sf lib${f:R:R} ${STAGEDIR}${PREFIX}/lib/lib${f:R:R:R}
.endfor

.include <bsd.port.mk>
