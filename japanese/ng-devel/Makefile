# Created by: Kawaguti Ginga <ginga-freebsd@ginganet.org>
# $FreeBSD$

PORTNAME=	ng
DISTVERSION=	1.5beta1
CATEGORIES=	japanese editors
MASTER_SITES=	http://tt.sakura.ne.jp/~amura/archives/ng/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light Emacs-clone with Japanese support

CONFLICTS=	ng-[0-9]*

USES=		ncurses
GNU_CONFIGURE=	yes
ALL_TARGET=	ng
CFLAGS+=	-Wno-error=return-type

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}
PORTDOCS=	${MYPORTDOCS:S/$/.euc-jp/}
PLIST_FILES=	bin/ng

OPTIONS_DEFINE=	CANNA DOCS

CANNA_DESC=		Canna support
CANNA_LIB_DEPENDS=	libcanna.so:japanese/canna-lib
CANNA_CONFIGURE_ON=	--enable-canna=${LOCALBASE}

MYPORTDOCS=	CHANGES.1_3 CHANGES.1_4 CHANGES.doc Ng.FAQ Ng.doc \
		Ng.ref Ng.tut README.Ng README.SKG

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ng \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${MYPORTDOCS}
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR}/${i:S/$/.euc-jp/})
.endfor

.include <bsd.port.mk>
