# Created by: Rashid N. Achilov <citycat4@ngs.ru>
# $FreeBSD$

PORTNAME=	yui
PORTVERSION=	3.2.06
CATEGORIES=	editors
MASTER_SITES=	http://www.sheltonsoft.ru/fileZ/software/ \
		http://www.askd.ru/~shelton/design/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rich-featured multi-windows console text editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BROKEN_aarch64=		fails to compile: cast from pointer to smaller type loses information
BROKEN_armv6=		fails to link: undefined reference to HTAnchor_physical
BROKEN_armv7=		fails to link: undefined reference to HTAnchor_physical
BROKEN_mips64=		fails to compile: cast from unsigned char* to unsigned int loses precision
BROKEN_sparc64=		fails to compile
BROKEN_powerpc64=	fails to build: strip: open tyui/y failed: No such file or directory

USES=		tar:bzip2
USE_AUTOTOOLS=	autoconf aclocal

ACLOCAL_ARGS=	-I m4
MAKE_ENV=	LIBPATH=${PREFIX}/lib

OPTIONS_DEFINE=	DOCS

post-install:
	${LN} -sf help_eng.html ${STAGEDIR}${PREFIX}/lib/yui/yhelp.html

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in BUGS CHANGES TODO THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
