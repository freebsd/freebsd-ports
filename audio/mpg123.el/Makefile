# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpg123.el
PORTVERSION=	1.52
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end to mpg123/ogg123 audio player for Emacsen

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${PORTNAME}-${PORTVERSION}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

myFETCH_CMD=	${FETCH_CMD} -AR

BROKEN=		fails to fetch

do-fetch:
	${myFETCH_CMD} ${FETCH_BEFORE_ARGS} ${MASTER_SITES}/mpg123el.cgi?${PORTVERSION}

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${ELISPDIR}/${PORTNAME}
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${PORTNAME} ${XELISPDIR}/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
