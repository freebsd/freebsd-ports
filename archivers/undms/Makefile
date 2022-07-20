PORTNAME=	undms
PORTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	http://de.aminet.net/pub/aminet/misc/unix/ \
		http://se2.aminet.net/pub/aminet/misc/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}.c
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/undms

do-extract:
	${MKDIR} ${WRKSRC}
	${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKSRC}/${DISTNAME}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
