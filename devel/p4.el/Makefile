PORTNAME=	p4.el
PORTVERSION=	10.6
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	SF/p4el/p4el/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perforce-Emacs Integration

RUN_DEPENDS=	p4:devel/p4

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/p4.el ${STAGEDIR}${EMACSLISPDIR}

.include <bsd.port.mk>
