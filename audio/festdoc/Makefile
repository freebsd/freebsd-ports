# Created by: trevor
# $FreeBSD$

PORTNAME=	festdoc
PORTVERSION=	1.4.0.1
CATEGORIES=	audio accessibility
MASTER_SITES=	FESTIVAL/1.4.1
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation for Festival

USES=		makeinfo
NO_BUILD=	yes

INFO=		festival
FDOC=		${PREFIX}/share/doc/festival

post-extract:
	${RM} ${WRKSRC}/festival/src-manual/c3750.htm~
	${RM} ${WRKSRC}/speechtools/c16909.htm~
	${RMDIR} ${WRKSRC}/festival/src-manual/images_gen

do-install:
	${MKDIR} ${STAGEDIR}${FDOC}
	${RM} ${WRKSRC}/festival/info/festival.info.orig
	cd ${WRKSRC} && info=`${FIND} . -name '*.info*' -type f` && \
	  ${CP} $$info ${STAGEDIR}${PREFIX}/info && \
	  ${CP} -r ${WRKSRC}/* ${STAGEDIR}${FDOC} && \
	  cd ${STAGEDIR}${FDOC} && \
	  ${RM} $$info && \
	  ${RMDIR} festival/info

.include <bsd.port.mk>
