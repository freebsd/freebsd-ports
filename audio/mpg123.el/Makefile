# New ports collection makefile for:	mpg123.el
# Date created:		99/10/6
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpg123.el
PORTVERSION=	1.40
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
DISTNAME =	${PORTNAME}-${PORTVERSION}
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

myFETCH_CMD=	/usr/bin/fetch -AR

do-fetch:
	${myFETCH_CMD} ${FETCH_BEFORE_ARGS} ${MASTER_SITES}/mpg123el.cgi?${PORTVERSION}

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${ELISPDIR}/${PORTNAME}
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${PORTNAME} ${XELISPDIR}/${PORTNAME}

.include <bsd.port.mk>
