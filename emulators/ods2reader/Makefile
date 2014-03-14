# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	ods2reader
PORTVERSION=	19930601
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.vsm.com.au/ftp/KITS/ \
		http://vms.process.com/ftp/vms-freeware/fileserv/ \
		http://web.infoave.net/~anonymous/VMS/
DISTNAME=	ODS-2-READER
EXTRACT_SUFX=	.ZIP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Copies files from VMS Files-11 (ODS2) file systems

USES=		zip:infozip
EXTRACT_BEFORE_ARGS=	-qoa
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ods2reader

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ods2reader ${WRKSRC}/ods-2-reader.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ods2reader ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
