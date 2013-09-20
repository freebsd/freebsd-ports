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

MAINTAINER=	m.boyarov@bsd.by
COMMENT=	RPM spec file editing commands for [X]Emacs

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/${PORTNAME} \
		lib/xemacs/site-lisp/${PORTNAME}
PLIST_DIRS=	lib/xemacs/site-lisp lib/xemacs

NO_STAGE=	yes
do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${EMACSLISPDIR}/${PORTNAME}
	${LN} -sf ${EMACSLISPDIR}/${PORTNAME} ${XEMACSLISPDIR}/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
