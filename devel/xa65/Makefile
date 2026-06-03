PORTNAME=	xa65
PORTVERSION=	2.4.1
CATEGORIES=	devel
MASTER_SITES=	http://www.floodgap.com/retrotech/xa/dists/
DISTNAME=	xa-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Two-pass cross-assembler for MOS 6502 and compatible CPUs
WWW=		https://www.floodgap.com/retrotech/xa/

LICENSE=	GPLv2+

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xa ${STAGEDIR}${PREFIX}/bin/xa65
.for file in file65 ldo65 reloc65 printcbm uncpk
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${LN} -sf xa.1 ${STAGEDIR}${PREFIX}/share/man/man1/xa65.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ChangeLog README.1st TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
