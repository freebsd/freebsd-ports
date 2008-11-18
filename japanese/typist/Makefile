# New ports collection makefile for:	typist
# Date created:			26 May 1997
# Whom:				Satoshi TAOKA
#
# $FreeBSD$
#

PORTNAME=	typist
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://tuba.csedu.kobe-u.ac.jp/pub/UNIX/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Typing lessons (Japanese version)

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		typist.1

.ifndef (NOPORTDOCS)
PORTDOCS=	INSTALL.txt README.J README.orig
.endif

OPTIONS=	KEYMAP106JP	"Japanese 106 Keymap"	on \
		KEYMAP101	"101 Keymap"		off

.include <bsd.port.pre.mk>

.if defined(WITH_KEYMAP101)
MAKE_ARGS=	KEYTYPE="e"
.elif !defined(WITHOUT_KEYMAP106JP)
MAKE_ARGS=	KEYTYPE="j"
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/typist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/../doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
