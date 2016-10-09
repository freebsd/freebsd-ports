# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	tass64
PORTVERSION=	1.51.727
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/source
DISTNAME=	64tass-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	6502/65C02/R65C02/W65C02/65CE02/65816/DTV/65EL02 Turbo Assembler

LICENSE=	GPLv2

USES=		gmake zip
MAKE_ARGS=	-w CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/tass64 \
		%%DOCSDIR%%/README \
		%%DOCSDIR%%/README.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/64tass ${STAGEDIR}${PREFIX}/bin/tass64
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in README README.html
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
