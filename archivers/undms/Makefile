# Created by: will
# $FreeBSD$

PORTNAME=	undms
PORTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/misc/unix/ \
		ftp://us.aminet.net/misc/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}.c
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts .dms Amiga disk images to uncompressed .adf images

NO_STAGE=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/undms

do-extract:
	${MKDIR} ${WRKDIR}
	${GZCAT} ${DISTDIR}/${DISTFILES} > ${WRKDIR}/${DISTNAME}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o undms undms-1.3.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/undms ${PREFIX}/bin/

.include <bsd.port.mk>
