# New ports collection makefile for:	unzip
# Date created:		17 October 1994
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	unzip
PORTVERSION=	5.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/infozip/src/
DISTNAME=	${PORTNAME}541

MAINTAINER=	ache@FreeBSD.org

Y2K=		ftp://ftp.info-zip.org/pub/infozip/FAQ.html#Y2K

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_UNZIP="${CFLAGS} -DUSE_SMITH_CODE -DUSE_UNSHRINK" -f
MAN1=		funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
ALL_TARGET=	freebsd
.else
ALL_TARGET=	bsd
.endif

do-install:
.for file in funzip unzip unzipsfx
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	${INSTALL_SCRIPT} ${WRKSRC}/unix/zipgrep ${PREFIX}/bin
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/unzip
.for file in README COPYING WHERE
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/unzip
.endfor
.endif

.include <bsd.port.post.mk>
