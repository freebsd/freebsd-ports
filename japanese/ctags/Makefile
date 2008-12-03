# New ports collection makefile for:   Exuberant Ctags with Japanese support
# Date created:        29 May 2007
# Whom:                issei
#
# $FreeBSD$
#

PORTNAME=	ctags
PORTVERSION=	5.7j1
CATEGORIES=	japanese devel
MASTER_SITES=	http://hp.vector.co.jp/authors/VA025040/ctags/downloads/

MAINTAINER=	issei@issei.org
COMMENT=	A feature-filled tagfile generator with Japanese support

WRKSRC=	${WRKDIR}/${DISTNAME:S/j1//}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --with-readlib

MAN1=		jexctags.1

SUB_FILES=	pkg-message

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README README_J.TXT
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${PREFIX}/bin/jexctags
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
