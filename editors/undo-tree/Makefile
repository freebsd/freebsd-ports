PORTNAME=	undo-tree
DISTVERSION=	0.8.2
CATEGORIES=	editors elisp
MASTER_SITES=	https://elpa.gnu.org/packages/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Treat Emacs undo history as a tree of changes
WWW=		https://elpa.gnu.org/packages/undo-tree.html

LICENSE=	GPLv3+

RUN_DEPENDS=	queue>=0.2:devel/queue

USES=		emacs:build tar:lz

NO_ARCH=	yes

PLIST_FILES=	${ELISP_FILES:S|^|${ELISPDIR}/|}

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	undo-tree-autoloads.el undo-tree.el

do-build:
	${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/undo-tree-autoloads.el ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${ELISP_FILES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

.include <bsd.port.mk>
