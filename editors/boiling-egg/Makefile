# New ports collection makefile for:	boiling-egg
# Date created:		9 January 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	boiling-egg
PORTVERSION=	0.02
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.gcd.org/sengoku/boiling-egg/
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

RUN_DEPENDS=	${ELISPDIR}/egg/egg.el:${PORTSDIR}/editors/tamago

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${ELISPDIR}

.include <bsd.port.mk>
