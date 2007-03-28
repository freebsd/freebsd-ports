# New ports collection makefile for:   yui
# Date created:                19 Mar 2007
# Whom:                        Rashid N. Achilov <citycat4@ngs.ru>
#
# $FreeBSD$
#

PORTNAME=	yui
PORTVERSION=	3.2.02
CATEGORIES=	editors
MASTER_SITES=	http://www.askd.ru/~shelton/fileZ/

MAINTAINER=	achilov-rn@askd.ru
COMMENT=	Rich-featured multi-windows console text editor

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:259

MAN1=		y.1

post-install:
	${LN} -sf ${PREFIX}/lib/yui/help_eng.html ${PREFIX}/lib/yui/yhelp.html

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES COPYRIGHT TODO COPYRIGHT.ITK
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
