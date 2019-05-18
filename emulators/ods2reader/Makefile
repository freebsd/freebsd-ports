# Created by: Jeffrey H. Johnson <CPE1704TKS@bellsouth.net>
# $FreeBSD$

PORTNAME=	ods2reader
PORTVERSION=	19930601
PORTREVISION=	1
CATEGORIES=	emulators sysutils
MASTER_SITES=	http://www.vsm.com.au/ftp/KITS/ \
		http://vms.process.com/ftp/vms-freeware/fileserv/
DISTNAME=	ODS-2-READER
EXTRACT_SUFX=	.ZIP

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Copies files from VMS Files-11 (ODS2) file systems

USES=		zip
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ods2reader

post-extract:
# The source is in OpenVMS' variable-length record format
	@${SH} ${FILESDIR}/vmsvlr2unix.sh \
		${WRKSRC}/ods-2-reader.c > ${WRKSRC}/ods-2-reader.new.c

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/ods2reader ${WRKSRC}/ods-2-reader.new.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ods2reader ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
