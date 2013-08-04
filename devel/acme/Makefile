# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	acme
PORTVERSION=	091
CATEGORIES=	devel
MASTER_SITES=	http://www.esw-heim.tu-clausthal.de/~marco/smorbrod/acme/current/
DISTNAME=	${PORTNAME}${PORTVERSION}src

MAINTAINER=	uffe@uffe.org
COMMENT=	Crossassembler for 6502, 65c02 and 65816 processors

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_BZIP2=	yes
USES=	gmake

BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
WRKSRC=	${WRKDIR}/${PORTNAME}${PORTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	bin/acme \
		%%DATADIR%%/6502 \
		%%DATADIR%%/6502/Help.txt \
		%%DATADIR%%/6502/std.a \
		%%DATADIR%%/65816 \
		%%DATADIR%%/65816/Help.txt \
		%%DATADIR%%/65816/std.a \
		%%DATADIR%%/Own \
		%%DATADIR%%/Own/Help.txt
PLIST_DIRSTRY=	%%DATADIR%%/6502 \
		%%DATADIR%%/65816 \
		%%DATADIR%%/Own \
		%%DATADIR%%

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/acme ${PREFIX}/bin

.for dir in 6502 65816 Own
	@${MKDIR} ${DATADIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/ACME_Lib/6502/* ${DATADIR}/6502
	${INSTALL_DATA} ${WRKSRC}/ACME_Lib/65816/* ${DATADIR}/65816
	${INSTALL_DATA} ${WRKSRC}/ACME_Lib/Own/* ${DATADIR}/Own

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/me
	${INSTALL_DATA} ${WRKSRC}/examples/*.a ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/me/*.a ${EXAMPLESDIR}/me/
.endif

.include <bsd.port.mk>
