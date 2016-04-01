# Created by: Kawaguti Ginga <ginga@athena.club.ne.jp>
# $FreeBSD$

PORTNAME=	ng
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	japanese editors
MASTER_SITES=	http://tt.sakura.ne.jp/~amura/archives/ng/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ng-1.4.4-replace_bug.patch

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Light Emacs-clone with Japanese support

USES=		ncurses
MAKEFILE=	sys/sysv/Makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LDFLAGS}"
ALL_TARGET=	ng

CFLAGS+=	-Wno-error=return-type
LDFLAGS+=	-lncurses

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

CONFLICTS=	ng-devel-[0-9]*

PORTDOCS=	${MYPORTDOCS:C/$/.euc-jp/}
PLIST_FILES=	bin/ng

OPTIONS_DEFINE=		CANNA DOCS

CANNA_DESC=		Canna support
CANNA_LIB_DEPENDS=	libcanna.so:japanese/canna-lib
CANNA_CFLAGS=		-I${LOCALBASE}/include -DCANNA
CANNA_LDFLAGS=		-L${LOCALBASE}/lib -lcanna

MYPORTDOCS=	CHANGES.1_3 CHANGES.doc Ng.FAQ Ng.doc Ng.ref Ng.tut \
		README.Ng README.SKG

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ng \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${MYPORTDOCS}
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR}/${i:S/$/.euc-jp/})
.endfor

.include <bsd.port.mk>
