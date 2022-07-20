PORTNAME=	boiling-egg
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.gcd.org/sengoku/boiling-egg/
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end of Egg V4

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	share/emacs/site-lisp
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${ELISPDIR}

.include <bsd.port.mk>
