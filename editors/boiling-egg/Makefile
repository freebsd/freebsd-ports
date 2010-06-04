# New ports collection makefile for:	boiling-egg
# Date created:		9 January 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	boiling-egg
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.gcd.org/sengoku/boiling-egg/
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A front-end of Egg V4

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	share/emacs/site-lisp
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

do-install:
	${MKDIR} ${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${PREFIX}/${ELISPDIR}

.include <bsd.port.mk>
