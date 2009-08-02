# ports collection makefile for:	fam
# Date created:				20 February 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	fam
PORTVERSION=	2.6.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A file alteration monitor

CFLAGS+=	-Wno-deprecated

USE_AUTOTOOLS=	aclocal:19 automake:19 autoconf:262 libtool:22
AUTOMAKE_ARGS=	-c -a
USE_GMAKE=	yes
USE_GNOME=	gnometarget
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
