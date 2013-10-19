# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	xa
PORTVERSION=	2.3.5
CATEGORIES=	devel
MASTER_SITES=	http://www.floodgap.com/retrotech/xa/dists/
PKGNAMESUFFIX=	65

MAINTAINER=	uffe@uffe.org
COMMENT=	MOS-6502 two-pass cross-assembler for MOS 6502 and compatible CPUs

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=	gmake

MAKE_ARGS= CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"

MAN1=	file65.1 ldo65.1 printcbm.1 reloc65.1 uncpk.1 xa.1
MLINKS=	xa.1 xa65.1

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	bin/xa65 \
		bin/file65 \
		bin/ldo65 \
		bin/reloc65 \
		bin/printcbm \
		bin/uncpk

NO_STAGE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xa ${PREFIX}/bin/xa65
.for file in file65 ldo65 reloc65 printcbm uncpk
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${man} ${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in COPYING ChangeLog README.1st TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
