# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	ratfor
PORTVERSION=	1985.06
PORTREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	LOCAL/obrien \
		http://sepwww.stanford.edu/sep/prof/
DISTFILES=	ratfor.shar.2 local.ratfor77.shar

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Rational FORTRAN compiler

BROKEN_aarch64=		./ratfor -o test.f test.r keeps creating huge output file
BROKEN_powerpc=		./ratfor -o test.f test.r keeps creating huge output file
BROKEN_powerpc64=	./ratfor -o test.f test.r keeps creating huge output file

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SH}
ALL_TARGET=	all tests
USES=		fortran

PLIST_FILES=	bin/ratfor bin/ratfor77 man/man1/ratfor.1.gz

post-patch:
	@${PATCH} -d ${WRKSRC} --quiet < ${WRKSRC}/testw.patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/ratfor77 ${STAGEDIR}${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
