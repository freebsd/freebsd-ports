# Created by: proff
# $FreeBSD$

PORTNAME=	an
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast anagram generator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz

post-patch:
	@${REINPLACE_CMD} -e '/<stdint.h>/d' ${WRKSRC}/an.c

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} an.c gan_qsort.c \
		-o ${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/an ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/an.6 ${STAGEDIR}${MANPREFIX}/man/man6

.include <bsd.port.mk>
