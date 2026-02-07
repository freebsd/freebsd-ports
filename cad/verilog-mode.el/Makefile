PORTNAME=	verilog-mode.el
PORTVERSION=	801
PORTREVISION=	24
CATEGORIES=	cad elisp
MASTER_SITES=	http://www.veripool.org/ftp/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME:R}-${PORTVERSION}.${PORTNAME:E}
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp modules for the Verilog language
WWW=		https://www.veripool.org/wiki/verilog-mode

LICENSE=	GPLv3+

EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	> ${PORTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		emacs:run

CONFLICTS_INSTALL=	verilog-mode.el verilog-mode.el-emacs_* # share/emacs/site-lisp/verilog-mode.el

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
