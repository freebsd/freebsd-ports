# New ports collection makefile for:	gemcal
# Date Created:				10 May 2001
# Whom:					Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gemcal
PORTVERSION=	20050120
CATEGORIES=	deskutils
MASTER_SITES=	http://www.quickhack.net/mhc/arc/
DISTNAME=	mhc-current-snap${PORTVERSION}

MAINTAINER?=	yoichi@FreeBSD.org
COMMENT=	Calendar program for MHC

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk

USE_RUBY=	yes

do-build:
	@(cd ${BUILD_WRKSRC}; ${RUBY} configure.rb --disable-palm --with-icondir=${PREFIX}/share/gemcal/xpm)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gemcal ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ruby-ext/lib/mhc-*.rb ${RUBY_SITELIBDIR}
	${MKDIR} ${PREFIX}/share/gemcal/xpm
	${INSTALL_DATA} ${WRKSRC}/00copyright ${PREFIX}/share/gemcal
	${INSTALL_DATA} ${WRKSRC}/xpm/*.xpm ${PREFIX}/share/gemcal/xpm

.include <bsd.port.mk>
