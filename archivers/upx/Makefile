# New ports collection makefile for:	upx
# Date created:				17 Feb 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	upx
PORTVERSION=	3.03
CATEGORIES=	archivers
MASTER_SITES=	http://upx.sourceforge.net/download/\
		SF/sevenzip/7-Zip/4.57:lzma
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}\
		7z${LZMA_VER:S/.//g}${EXTRACT_SUFX}:lzma

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The Ultimate Packer for eXecutables

LIB_DEPENDS=	ucl.1:${PORTSDIR}/archivers/ucl

LZMA_VER=	4.57
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ENV=	UPX_UCLDIR=${LOCALBASE}\
		UPX_LZMADIR=${WRKDIR}\
		target=freebsd
NOT_FOR_ARCHS=	sparc64

PORTDOCS=	BUGS COPYING LICENSE NEWS PROJECTS README\
		README.1ST README.SRC THANKS TODO
MAN1=		upx.1
PLIST_FILES=	bin/upx

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${PREFIX}/bin/upx
	@${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
