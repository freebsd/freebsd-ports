# Created by: Pedro F. Giffuni <giffunip@asme.org>

PORTNAME=	z88
DISTVERSIONPREFIX=	v
DISTVERSION=	15
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compact Finite Element Analysis System

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12_powerpc64=	fails to link: /usr/bin/ld: : No such file: No such file or directory

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gl gnome pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11

GH_ACCOUNT=	LSCAD
GH_PROJECT=	Z88OS

BUILD_WRKSRC=	${WRKSRC}/make/make_unix_64
INSTALL_WRKSRC=	${WRKSRC}/bin/unix64

Z88_BIN_SUFFIXES=	g h n r o x
Z88_DATA=	51.txt z88.dyn z88.fcd z88elp.txt z88i1.txt z88i2.txt z88i5.txt z88int.txt \
		z88man.txt z88mat.txt z88ni.txt z88o0.txt z88o1.txt z88o2.txt z88o3.txt z88o4.txt z88o5.txt z88o8.txt z88x.dxf

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	for x in ${BUILD_WRKSRC}/*; do ${REINPLACE_CMD} 's,z88v15os,Z88OS-15, ; s,gcc,${CC}, ; s,CFLAGS =,CFLAGS+=, ; s,-O2,, ; s,LDLIBSOX,LDFLAGS, ; s,LDFLAGS =,LDFLAGS+=, ; s,--copy-dt-needed-entries,,' $$x; done

post-patch-DOCS-on:
	${REINPLACE_CMD} 's,%%DOCSDIR%%,${DOCSDIR},' ${INSTALL_WRKSRC}/z88.fcd

do-build:
	cd ${BUILD_WRKSRC}; for x in com ${Z88_BIN_SUFFIXES}; do ${SETENV} ${MAKE_ENV} ${MAKE} -f z88$$x.mk.gcc64 z88$$x ; done

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/z88com ${STAGEDIR}${DATADIR}
	for x in ${Z88_BIN_SUFFIXES}; do ${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/z88$$x ${STAGEDIR}${PREFIX}/bin; done
	${INSTALL_DATA} ${Z88_DATA:S,^,${INSTALL_WRKSRC}/,} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/z88 ${STAGEDIR}${PREFIX}/bin
	${SED} -i '' 's,%%DATADIR%%,${DATADIR},' ${STAGEDIR}${PREFIX}/bin/z88
	${SED} -i '' 's,%%Z88_DATA%%,${Z88_DATA},' ${STAGEDIR}${PREFIX}/bin/z88

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for x in e g; do ${INSTALL_DATA} ${WRKSRC}/docu/z88man$$x.pdf ${STAGEDIR}${DOCSDIR}; done

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
