# Created by: issei
# $FreeBSD$

PORTNAME=	ctags
PORTVERSION=	5.8j2
CATEGORIES=	japanese devel
MASTER_SITES=	http://hp.vector.co.jp/authors/VA025040/ctags/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A feature-filled tagfile generator with Japanese support

WRKSRC=	${WRKDIR}/${DISTNAME:S/j1//}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --with-readlib

MAN1=		jexctags.1

SUB_FILES=	pkg-message

NO_STAGE=	yes
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
