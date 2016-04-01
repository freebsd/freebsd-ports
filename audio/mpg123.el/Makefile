# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpg123.el
PORTVERSION=	1.52
PORTREVISION=	1
CATEGORIES=	audio elisp
MASTER_SITES=	http://www.gentei.org/~yuuji/software/mpg123el/
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty
DISTFILES=	mpg123el.cgi?${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end to mpg123/ogg123 audio player for Emacsen

RUN_DEPENDS=	mpg123:audio/mpg123

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${PORTNAME}-${PORTVERSION}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

FETCH_ARGS=	-AR
FETCH_BEFORE_ARGS=	-o mpg123el.cgi?${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR}
	${INSTALL_DATA} ${DISTDIR}/mpg123el.cgi?${PORTVERSION} ${STAGEDIR}${ELISPDIR}/${PORTNAME}
# For XEmacs
	@${MKDIR} ${STAGEDIR}${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${PORTNAME} ${STAGEDIR}${XELISPDIR}/${PORTNAME}

.include <bsd.port.mk>
