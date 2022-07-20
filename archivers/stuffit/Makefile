PORTNAME=	stuffit
PORTVERSION=	5.2.0.611
PORTREVISION=	1
CATEGORIES=	archivers linux
MASTER_SITES=	https://webdiis.unizar.es/pub/unix/archive/ \
		http://mirror.sobukus.de/files/grimoire/z-archive/
DISTNAME=	stuffit520.611linux-i386

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stuffit Archive Creator and Expander

# Converted from RESTRICTED
LICENSE=	STUFFIT
LICENSE_NAME=	STUFFIT
LICENSE_TEXT=	Only unmodified original package can be distributed
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	i386 amd64

USES=		linux
NO_WRKSUBDIR=	yes
STUFFIT_FILES=	bin/unstuff bin/stuff
STUFFIT_MAN=	man/man1/stuff.1 man/man1/unstuff.1
PLIST_FILES=	${STUFFIT_FILES} \
		${STUFFIT_MAN:S,$,.gz,}

do-build:
.for sFile in ${STUFFIT_FILES}
	${BRANDELF} -t Linux ${WRKSRC}/${sFile}
.endfor

do-install:
.for sFile in ${STUFFIT_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${sFile} ${STAGEDIR}${PREFIX}/bin
.endfor
.for mFile in ${STUFFIT_MAN}
	${INSTALL_MAN} ${WRKSRC}/${mFile} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
