# ports collection makefile for:	fam
# Date created:				20 February 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	fam
PORTVERSION=	2.6.10
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file alteration monitor

CFLAGS+=	-Wno-deprecated

USE_AUTOTOOLS=	aclocal automake autoconf libtool
AUTOMAKE_ARGS=	-c -a
USE_GMAKE=	yes
USE_LDCONFIG=	yes
ACLOCAL_ARGS=	-I "${ACLOCAL_DIR}" -I ${LOCALBASE}/share/aclocal
SUB_FILES=	pkg-message

MAN1=		fam.1m
MAN3=		fam.3x

CONFLICTS=	gamin-[0-9]*

pre-configure:
	@${RM} -fr ${WRKSRC}/util
	@${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	@${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}/fam

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
