# New ports collection makefile for:    unzip
# ftp://ftp.info-zip.org/pub/infozip/Info-ZIP.html
# Date created:         17 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	unzip
PORTVERSION=    5.41
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.freesoftware.com/pub/infozip/src/
DISTNAME=       unzip541

MAINTAINER=	ache@FreeBSD.org

Y2K=            ftp://ftp.info-zip.org/pub/infozip/FAQ.html#Y2K

WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=       unix/Makefile
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS} -DUSE_SMITH_CODE -DUSE_UNSHRINK" -f
MAN1=           funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && \
		${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/man && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	${INSTALL} -d -m 555 -o ${SHAREOWN} -g ${SHAREGRP} ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && \
		${INSTALL_DATA} README COPYING WHERE ${PREFIX}/share/doc/unzip

.include <bsd.port.mk>

.if ${ARCH} == "alpha"
ALL_TARGET=	bsd
.else
ALL_TARGET=     freebsd
.endif
