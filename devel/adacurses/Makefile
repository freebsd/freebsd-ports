# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=		adacurses
PORTVERSION=		5.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	ncurses
DISTNAME=		ncurses-${PORTVERSION}

MAINTAINER=		sylvio@FreeBSD.org
COMMENT=		Curses library for Ada

LICENSE=	MIT

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/misc --disable-overwrite \
		--disable-termcap --includedir=${PREFIX}/include/ncurses \
		--with-profile --with-shared --without-debug \
		--without-curses-h --with-termlib --with-libtool
CONFIGURE_ENV=	ac_cv_path_LDCONFIG="${LDCONFIG} -m ${PREFIX}/lib" \
		 ADA_SUBDIRS="gen src"

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/adacurses
	@${INSTALL_DATA} ${WRKSRC}/Ada95/src/*.ads ${PREFIX}/lib/adacurses
	@${INSTALL_DATA} ${WRKSRC}/Ada95/src/*.adb ${PREFIX}/lib/adacurses
	@${INSTALL_SCRIPT} ${FILESDIR}/adacurses-config ${PREFIX}/bin

.include <bsd.port.mk>
