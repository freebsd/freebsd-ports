# ports collection makefile for:	fam
# Date created:				20 February 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=		fam
PORTVERSION=		2.6.9
CATEGORIES=		devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/
PATCH_SITES=		ftp://oss.sgi.com/projects/fam/download/patches/
PATCH_DIST_STRIP=	-p1
PATCHFILES=		freebsd-mntent.patch # freebsd-build.patch

MAINTAINER=		ports@geeksrus.net

USE_AUTOMAKE_VER=14
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=		fam.1m
MAN3=		fam.3x

pre-configure:
	${RM} -fr ${WRKSRC}/util
	${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am

post-install:
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/fam.sh.sample ${PREFIX}/etc/rc.d/fam.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
