# New ports collection makefile for:   yui
# Date created:                19 Mar 2007
# Whom:                        Rashid N. Achilov <citycat4@ngs.ru>
#
# $FreeBSD$
#

PORTNAME=	yui
PORTVERSION=	3.2.04
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://openoffice.mirahost.ru/fileZ/software/ \
		http://citycat4.land.ru/ \
		http://myooo.ru/FreeBSD/

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Rich-featured multi-windows console text editor

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:268

MAN1=		y.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/yui/help_eng.html ${PREFIX}/lib/yui/yhelp.html

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES COPYRIGHT TODO COPYRIGHT.ITK THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
