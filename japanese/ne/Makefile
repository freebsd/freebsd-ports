# New ports collection makefile for:    nxedit
# Date created:        15 Nov 1999
# Whom:                SASAKI Shunsuke <ele@pop17.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ne
PORTVERSION=	3.04
CATEGORIES=	japanese editors
MASTER_SITES=	http://hp.vector.co.jp/authors/VA018758/archive/

MAINTAINER=	ele@pop17.odn.ne.jp
COMMENT=	A VZ like full-screen text editor with Japanese support

WRKSRC=		${WRKDIR}/ne
GNU_CONFIGURE=	yes
MAN1=		ne.1
MANLANG=	ja
DOCS=		BUGS.jp CHANGES.jp HISTORY.jp INSTALL.jp README.jp TODO.jp
MAKE_ENV=	LANG=${MANLANG}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ne
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/ne
.endfor
.endif

.include <bsd.port.post.mk>
