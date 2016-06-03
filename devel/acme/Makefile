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

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
OPTIONS_DEFINE=	DOCS EXAMPLES

USES=	gmake tar:bzip2

BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
WRKSRC=	${WRKDIR}/${PORTNAME}${PORTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	bin/acme \
		%%DATADIR%%/6502/Help.txt \
		%%DATADIR%%/6502/std.a \
		%%DATADIR%%/65816/Help.txt \
		%%DATADIR%%/65816/std.a \
		%%DATADIR%%/Own/Help.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/acme ${STAGEDIR}${PREFIX}/bin
.for dir in 6502 65816 Own
	@${MKDIR} ${STAGEDIR}${DATADIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/ACME_Lib/6502/* ${STAGEDIR}${DATADIR}/6502
	${INSTALL_DATA} ${WRKSRC}/ACME_Lib/65816/* ${STAGEDIR}${DATADIR}/65816
	${INSTALL_DATA} ${WRKSRC}/ACME_Lib/Own/* ${STAGEDIR}${DATADIR}/Own
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/me
	${INSTALL_DATA} ${WRKSRC}/examples/*.a ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/me/*.a ${STAGEDIR}${EXAMPLESDIR}/me/

.include <bsd.port.mk>
