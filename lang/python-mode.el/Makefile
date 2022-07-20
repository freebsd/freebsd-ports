PORTNAME=	python-mode.el
PORTVERSION=	1.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	lang elisp python
MASTER_SITES=	SF/python-mode/OldFiles
DISTNAME=	python-mode-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp module for the Python language

NO_BUILD=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

LISPFILES=	doctest-mode.el pycomplete.el pycomplete.py python-mode.el

do-install:
	@${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
.for i in ${LISPFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${EMACSLISPDIR}
.endfor

.include <bsd.port.mk>
