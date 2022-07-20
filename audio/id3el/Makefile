PORTNAME=	id3el
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add-on to edit ID3 tags for mpg123-mode (mpg123.el) on Emacsen

RUN_DEPENDS=	mpg123.el>0:audio/mpg123.el

ALL_TARGET=	id3put

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/id3.el ${STAGEDIR}${ELISPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/id3put ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
