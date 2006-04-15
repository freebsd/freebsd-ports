# ports collection makefile for:	fam
# Date created:				20 February 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=		fam
PORTVERSION=		2.6.9
PORTREVISION=		6
CATEGORIES=		devel
MASTER_SITES=		ftp://oss.sgi.com/projects/fam/download/
PATCH_SITES=		ftp://oss.sgi.com/projects/fam/download/patches/
PATCH_DIST_STRIP=	-p1
PATCHFILES=		freebsd-mntent.patch # freebsd-build.patch
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file alteration monitor

CFLAGS+=		-Wno-deprecated

USE_AUTOTOOLS=	automake:15 autoconf:253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=		fam.1m
MAN3=		fam.3x

CONFLICTS=	gamin-[0-9]*

pre-configure:
	@${RM} -fr ${WRKSRC}/util
	@${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	@${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am
	@${RM} -f ${WRKSRC}/Makefile.am.orig
	@${RM} -f ${WRKSRC}/fam/mntent*
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}/fam
	@${REINPLACE_CMD} -e 's|$$lt_target|$$host|' \
		-e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
