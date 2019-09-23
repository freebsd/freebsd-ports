# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	routino
PORTVERSION=	3.3.2
CATEGORIES=	astro
MASTER_SITES=	http://www.routino.org/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Router for OpenStreetMap Data

LICENSE=	AGPLv3

OPTIONS_DEFINE=	DOCS
USES=		compiler gmake perl5 tar:tgz
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} 's|doc/routino|share/doc/routino|' \
		${WRKSRC}/Makefile.conf
	${REINPLACE_CMD} 's|gcc|${CC}|' \
		${WRKSRC}/Makefile.conf
.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
	${REINPLACE_CMD} -e '/pragma/d' ${WRKSRC}/src/xmlparse.c
.endif

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/web && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name Makefile")
	${RM} ${STAGEDIR}${PREFIX}/lib/libroutino*.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libroutino*.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/bin/*
.for f in routino.so.0.0.0 routino-slim.so.0.0.0
	${LN} -sf lib${f} ${STAGEDIR}${PREFIX}/lib/lib${f:R:R}
	${LN} -sf lib${f:R:R} ${STAGEDIR}${PREFIX}/lib/lib${f:R:R:R}
.endfor

.include <bsd.port.post.mk>
