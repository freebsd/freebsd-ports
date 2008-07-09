# New ports collection makefile for:   yui
# Date created:                19 Mar 2007
# Whom:                        Rashid N. Achilov <citycat4@ngs.ru>
#
# $FreeBSD$
#

PORTNAME=	yui
PORTVERSION=	3.2.03
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.askd.ru/~shelton/fileZ/

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Rich-featured multi-windows console text editor

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:261

MAN1=		y.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on 64-bit arch
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/yui/help_eng.html ${PREFIX}/lib/yui/yhelp.html

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES COPYRIGHT TODO COPYRIGHT.ITK
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
