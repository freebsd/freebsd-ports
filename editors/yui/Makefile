# Created by: Rashid N. Achilov <citycat4@ngs.ru>
# $FreeBSD$

PORTNAME=	yui
PORTVERSION=	3.2.06
CATEGORIES=	editors
MASTER_SITES=	http://www.sheltonsoft.ru/fileZ/software/ \
		http://www.askd.ru/~shelton/design/

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Rich-featured multi-windows console text editor

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf aclocal

ACLOCAL_ARGS+=	-I m4

MAKE_ENV+=	LIBPATH=${PREFIX}/lib

MAN1=		y.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/yui/help_eng.html ${PREFIX}/lib/yui/yhelp.html

.if $(PORT_OPTIONS:MDOCS)

	@${MKDIR} ${DOCSDIR}

.for file in BUGS CHANGES COPYRIGHT TODO COPYRIGHT.ITK THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor

.endif

.include <bsd.port.post.mk>
