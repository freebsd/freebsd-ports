# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.1-rc1
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

pre-configure:
	find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@LIBPYTHON =@LIBPYTHON= ${PTHREAD_LIBS}@g"
	${PERL} -pi -e "s@la_LIBADD =@la_LIBADD= ${PTHREAD_LIBS}@g" \
		${WRKSRC}/kivio/plugins/*/Makefile.in
	${PERL} -pi -e "s@Exec=kivio@Exec=env LD_PRELOAD=/usr/lib/libc_r.so kivio@g" \
		${WRKSRC}/kivio/kiviopart/kivio.desktop

post-install:
	${MV} ${PREFIX}/bin/kivio ${PREFIX}/bin/kivio.real
	${INSTALL_SCRIPT} ${FILESDIR}/kivio.sh ${PREFIX}/bin/kivio

.include <bsd.port.mk>
