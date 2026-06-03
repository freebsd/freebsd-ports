PORTNAME=	unar
PORTVERSION=	1.10.1
PORTREVISION=	27
CATEGORIES=	archivers gnustep
MASTER_SITES=	http://wakaba.c3.cx/releases/TheUnarchiver/
DISTNAME=	${PORTNAME}${PORTVERSION}_src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Unarchiver for a vast variety of file formats
WWW=		https://unarchiver.c3.cx/commandline

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/License.txt

# XXX: USES=gnustep overrides MAKEFILE we set below, so depend explicitly
LIB_DEPENDS=	libgnustep-base.so:lang/gnustep-base \
		libicuuc.so:devel/icu \
		libwavpack.so:audio/wavpack

USES=		gmake zip

MAKEFILE=	Makefile.freebsd
WRKSRC=		${WRKDIR}/The\ Unarchiver
BUILD_WRKSRC=	${WRKSRC}/XADMaster

PLIST_FILES=	bin/lsar bin/unar share/man/man1/lsar.1.gz share/man/man1/unar.1.gz
PORTDOCS=	README.md
PORTEXAMPLES=	lsar.bash_completion unar.bash_completion

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/XADMaster/??ar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Extra/??ar.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Extra/??ar.bash_completion \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
