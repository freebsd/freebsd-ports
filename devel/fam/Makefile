# ports collection makefile for:	fam
# Date created:				20 February 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	fam
PORTVERSION=	2.6.8
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/

MAINTAINER=	ports@geeksrus.net

USE_AUTOMAKE_VER=14
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=		fam.1m
MAN3=		fam.3x

pre-configure:
	${RM} -fr ${WRKSRC}/util
	${CP} ${FILESDIR}/fam-mntent.h ${WRKSRC}/fam/mntent.h
	${CP} ${FILESDIR}/fam-mntent_compat.c++ ${WRKSRC}/fam/mntent_compat.c++
	${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/fam.sh.sample ${PREFIX}/etc/rc.d/fam.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
