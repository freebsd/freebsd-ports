PORTNAME=	queue
DISTVERSION=	0.2
CATEGORIES=	devel elisp
MASTER_SITES=	https://elpa.gnu.org/packages/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Queue data structure for Emacs Lisp
WWW=		https://elpa.gnu.org/packages/queue.html

LICENSE=	GPLv3+

USES=		emacs:build tar:lz

NO_ARCH=	yes

PLIST_FILES=	${ELISP_FILES:S|^|${ELISPDIR}/|}

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	queue-autoloads.el queue.el

do-build:
	${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/queue-autoloads.el ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${ELISP_FILES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

.include <bsd.port.mk>
