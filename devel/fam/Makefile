# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	fam
PORTVERSION=	2.6.10
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File alteration monitor

CFLAGS+=	-Wno-deprecated

USES=		gmake
USE_AUTOTOOLS=	aclocal automake autoconf libtool
AUTOMAKE_ARGS=	-c -a
USE_LDCONFIG=	yes
ACLOCAL_ARGS=	-I "${ACLOCAL_DIR}" -I ${LOCALBASE}/share/aclocal
SUB_FILES=	pkg-message

#CONFLICTS_INSTALL=	gamin-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e "s/-lstdc++//g" ${WRKSRC}/Makefile.am

pre-configure:
	@${RM} -fr ${WRKSRC}/util
	@${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	@${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}/fam

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfam.so.0

.include <bsd.port.mk>
