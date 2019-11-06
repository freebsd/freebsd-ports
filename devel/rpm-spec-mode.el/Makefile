# Created by: Max N. Boyarov <m.boyarov@gmail.com>
# $FreeBSD$

PORTNAME=	rpm-spec-mode.el
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://www.xemacs.org/~stigb/ \
		http://ncd0.bsd.by/ports/distfiles/
DISTNAME=	rpm-spec-mode.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	RPM spec file editing commands for Emacs

BROKEN=		unfetchable

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${EMACSLISPDIR}/${PORTNAME}

.include <bsd.port.mk>
