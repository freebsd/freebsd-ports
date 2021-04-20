PORTNAME=	z80pack
DISTVERSION=	1.37
CATEGORIES=	emulators
MASTER_SITES=	https://www.autometer.de/unix4fun/z80pack/ftp/
EXTRACT_SUFX=	tgz

MAINTAINER=	se@FreeBSD.org
COMMENT=	Complete CP/M-80 emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

do-build:
		${MAKE} -C ${WRKSRC}/cpmsim/srcsim -f Makefile.bsd OPTFLAGS="${CFLAGS}" PREFIX=${PREFIX} all clean
		${MAKE} -C ${WRKSRC}/cpmsim/srctools CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
.for file in mkdskimg bin2hex send receive ptp2bin
		${INSTALL_PROGRAM} ${WRKSRC}/cpmsim/srctools/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
		${INSTALL_PROGRAM} ${WRKSRC}/cpmsim/cpmsim ${STAGEDIR}${PREFIX}/bin
		cd ${WRKSRC}/cpmsim/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
		cd ${WRKSRC}/cpmsim/disks/library && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/disks

do-install-DOCS-on:
		cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
