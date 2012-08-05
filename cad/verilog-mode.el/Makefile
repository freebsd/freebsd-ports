# New ports collection makefile for:	verilog-mode.el
# Date created:		12 January 2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	verilog-mode.el
PORTVERSION=	801
CATEGORIES=	cad elisp
MASTER_SITES=	http://www.veripool.org/ftp/
DISTNAME=	${PORTNAME:R}-${PORTVERSION}.${PORTNAME:E}
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp modules for the Verilog language

LICENSE=	GPLv3 # (or later)

EXTRACT_AFTER_ARGS=	> ${PORTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_EMACS=	yes
EMACS_NO_BUILD_DEPENDS=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/${EMACS_SITE_LISPDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
