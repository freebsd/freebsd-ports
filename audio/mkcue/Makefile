PORTNAME=	mkcue
DISTVERSION=	${ORIGVERSION}-${DEBIANVERSION}
CATEGORIES=	audio
MASTER_SITES=	DEBIAN
DISTFILES=	${PORTNAME}_${ORIGVERSION}.orig.tar.gz \
		${PORTNAME}_${DISTVERSION}.debian.tar.xz

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Generates CUE sheets from a CD TOC (Table Of Contents)
WWW=		https://packages.debian.org/sid/mkcue

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man

ORIGVERSION=	1
DEBIANVERSION=	7

GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile

EXTRA_PATCHES=	${WRKDIR}/debian/patches/fix_msf_offset:-p1 \
		${WRKDIR}/debian/patches/use_ldflags:-p1

WRKSRC=		${WRKDIR}/${PORTNAME}-${ORIGVERSION}.orig

PLIST_FILES=	bin/mkcue \
		share/man/man1/mkcue.1.gz

post-build:
	docbook-to-man ${WRKDIR}/debian/mkcue.sgml > ${WRKDIR}/debian/mkcue.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkcue ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/debian/mkcue.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
