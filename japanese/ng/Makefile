# Created by: Kawaguti Ginga <ginga@athena.club.ne.jp>
# $FreeBSD$

PORTNAME=	ng
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	japanese editors
MASTER_SITES=	http://tomato.sakura.ne.jp/~amura/archives/ng/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ng-1.4.4-replace_bug.patch

MAINTAINER?=	ginga-freebsd@ginganet.org
COMMENT?=	Light Emacs-clone with Japanese support

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="${LIBS}"
LIBS=		-ltermcap

ALL_TARGET=	ng

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

MYPORTDOCS=	CHANGES.1_3 CHANGES.doc Ng.FAQ Ng.doc Ng.ref Ng.tut \
		README.Ng README.SKG
PORTDOCS=	${MYPORTDOCS:C/$/.euc-jp/}

PLIST_FILES=	bin/ng

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_CANNA)
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/canna-lib

CFLAGS+=	-I${LOCALBASE}/include -DCANNA
LIBS+=		-L${LOCALBASE}/lib -lcanna
.endif

post-patch:
	@(cd ${WRKSRC}; ${LN} -sf sys/sysv/Makefile . )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}/${file}.euc-jp
.endfor
.endif

.include <bsd.port.post.mk>
