# ex:ts=8
# New ports collection makefile for:	hypersrc
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hypersrc
PORTVERSION=	5.4.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/hypersrc/%SUBDIR%/ \
		http://www.home.earthlink.net/~jebrooks1/ftp/hypersrc/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code browser

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL5=	yes
USE_GNOME=	gnomelibs
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CC="${CC}" C_OPTIMIZE="${CFLAGS}"

MAN1=		hypersrc.1
PLIST_FILES=	bin/hypersrc bin/Hypersrc.pl bin/ctags.pl

post-patch:
	@${PERL} -pi -e 's|"ctags"|"${LOCALBASE}/bin/exctags"|g ; \
		 s|"ctags.pl"|"${PREFIX}/bin/ctags.pl"|g' ${WRKSRC}/Hypersrc.pl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/hypersrc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Hypersrc.pl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ctags.pl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hypersrc.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
