# New ports collection makefile for:	mkisofs
# Date created:		23 Mar 2001
# Whom:			cjh
#
# $FreeBSD$
#

PORTNAME=	mkisofs
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	korean sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/mkisofs/ \
		ftp://ftp.gwdg.de/pub/linux/misc/cdrecord/mkisofs/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/mkisofs/

PATCH_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
PATCHFILES=	mkisofs-1.13-cp949.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Create iso9660/Rock Ridge/Joliet filesystems supporting Korean

MAN8=		apple_driver.8 isoinfo.8 mkhybrid.8 mkisofs.8
USE_GMAKE=	yes
MAKE_ENV=	COPTX="-DBSD_SCSI_SENSE_BUG"

.if ${MACHINE_ARCH} != "i386"
post-extract:
	${LN} -s ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-cc.rul
.endif

post-build:
	@(cd ${WRKSRC}/mkisofs; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} apple_driver)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${ARCH}-freebsd-cc/mkisofs ${PREFIX}/bin
	@${LN} ${PREFIX}/bin/mkisofs ${PREFIX}/bin/mkhybrid
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/apple_driver ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/devdump ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isodump ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isoinfo ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/isovfy ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkhybrid.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/apple_driver.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
