PORTNAME=	ratfor
PORTVERSION=	1985.06
PORTREVISION=	17
CATEGORIES=	lang
MASTER_SITES=	LOCAL/obrien \
		http://sepwww.stanford.edu/sep/prof/
DISTFILES=	ratfor.shar.2 local.ratfor77.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rational FORTRAN compiler

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/README

USES=		fortran

ALL_TARGET=	all tests

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SH}

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/ratfor bin/ratfor77 share/man/man1/ratfor.1.gz

post-patch:
	@${PATCH} -d ${WRKSRC} --quiet < ${WRKSRC}/testw.patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/ratfor77 ${STAGEDIR}${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
