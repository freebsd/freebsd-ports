# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hypersrc
PORTVERSION=	5.4.21
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/hypersrc/%SUBDIR%/ \
		http://www.home.earthlink.net/~jebrooks1/ftp/hypersrc/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest old

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Source code browser

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL5=	yes
USE_GNOME=	gnomelibs
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC="${CC}" C_OPTIMIZE="${CFLAGS}"
USES=		shebangfix
SHEBANG_FILES=	Hypersrc.pl

MAN1=		hypersrc.1
PLIST_FILES=	bin/hypersrc bin/Hypersrc.pl bin/ctags.pl

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|"ctags"|"${LOCALBASE}/bin/exctags"|' \
		-e 's|"ctags.pl"|"${PREFIX}/bin/ctags.pl"|' ${WRKSRC}/Hypersrc.pl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/hypersrc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Hypersrc.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ctags.pl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hypersrc.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
