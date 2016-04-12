# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	upx
PORTVERSION=	3.91
CATEGORIES=	archivers
MASTER_SITES=	http://upx.sourceforge.net/download/\
		SF/sevenzip/7-Zip/${LZMA_VER}:lzma
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} \
		7z${LZMA_VER:S/.//g}${EXTRACT_SUFX}:lzma

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The Ultimate Packer for eXecutables

LIB_DEPENDS=	libucl.so:archivers/ucl

LZMA_VER=	4.65
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src
USES=		tar:bzip2 gmake perl5
USE_PERL5=	build
MAKE_ENV=	UPX_UCLDIR=${LOCALBASE}\
		UPX_LZMADIR=${WRKDIR}\
		target=freebsd
NOT_FOR_ARCHS=	sparc64

PORTDOCS=	BUGS COPYING LICENSE NEWS PROJECTS README\
		README.1ST README.SRC THANKS TODO
PLIST_FILES=	bin/upx \
		man/man1/upx.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${STAGEDIR}${PREFIX}/bin/upx
	@${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
