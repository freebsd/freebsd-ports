PORTNAME=	cd-discid
PORTVERSION=	0.9
CATEGORIES=	audio
MASTER_SITES=	http://lly.org/~rcw/cd-discid/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backend utility to retrieve CDDB discid information

WRKSRC=		${WRKDIR}/${PKGNAME}

MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX} mandir=${STAGEDIR}${PREFIX}/man/man1

PLIST_FILES=	bin/cd-discid \
		man/man1/cd-discid.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s/-o 0//g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
