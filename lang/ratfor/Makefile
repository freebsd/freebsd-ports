# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	ratfor
PORTVERSION=	1985.06
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}  \
		http://sepwww.stanford.edu/sep/prof/
MASTER_SITE_SUBDIR=	obrien
DISTFILES=	ratfor.shar.2 local.ratfor77.shar

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Ratfor -- the Rational FORTRAN compiler

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SH}
ALL_TARGET=	all tests
USES=		fortran

PLIST_FILES=	bin/ratfor bin/ratfor77 man/man1/ratfor.1.gz

post-patch:
	@cd ${WRKSRC} ; ${PATCH} --quiet < testw.patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/ratfor77 ${STAGEDIR}${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
