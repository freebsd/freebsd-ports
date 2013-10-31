# Created by: Kawaguti Ginga <ginga-freebsd@ginganet.org>
# $FreeBSD$

PORTNAME=	ng
PORTVERSION=	1.5.b1
CATEGORIES=	japanese editors
MASTER_SITES=	http://tomato.sakura.ne.jp/~amura/archives/ng/
DISTNAME=	${PORTNAME}-1.5beta1

MAINTAINER?=	ginga-freebsd@ginganet.org
COMMENT=	Light Emacs-clone with Japanese support

ALL_TARGET=	ng
GNU_CONFIGURE=	yes

MYPORTDOCS=	CHANGES.1_3 CHANGES.1_4 CHANGES.doc Ng.FAQ Ng.doc Ng.ref Ng.tut \
		README.Ng README.SKG
PKGNAMESUFFIX=	-devel
DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ng ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}/${file}.euc-jp
.endfor
.endif

.include <bsd.port.mk>
