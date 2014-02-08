# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picasm
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.jmp.fi/~trossi/pic/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable assembler for 16C84 series PICs

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-07

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

USES=		perl5
USE_PERL5=	build

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PERL5="${PERL5}"
ALL_TARGET=

EXAMPLE_FILES=	example.asm morse.asm morse.i pic16f84.i picmac.i

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picasm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/picasm.txt ${STAGEDIR}${DOCSDIR}
.for EXAMPLE in ${EXAMPLE_FILES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXAMPLE} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/device_definitions
	${INSTALL_DATA} ${WRKSRC}/device_definitions/*.i ${STAGEDIR}${DATADIR}/device_definitions

.include <bsd.port.mk>
