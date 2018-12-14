# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	upx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.95
CATEGORIES=	archivers

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Ultimate Packer for eXecutables

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libucl.so:archivers/ucl

USES=		gmake perl5
USE_GITHUB=	yes
USE_PERL5=	build # provides pod2man/pod2html/pod2text required for docs

GH_TUPLE=	upx:upx-lzma-sdk:${DISTVERSIONPREFIX}${DISTVERSION}:lzma/src/lzma-sdk

MAKE_ENV=	UPX_UCLDIR=${LOCALBASE} \
		target=freebsd

PORTDOCS=	BUGS COPYING LICENSE NEWS PROJECTS README \
		README.1ST README.SRC THANKS

PLIST_FILES=	bin/upx \
		man/man1/upx.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${STAGEDIR}${PREFIX}/bin/upx
	${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
