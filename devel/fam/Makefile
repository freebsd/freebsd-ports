# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	fam
PORTVERSION=	2.6.10
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File alteration monitor

CFLAGS+=	-Wno-deprecated

USES=		gmake libtool
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

#CONFLICTS_INSTALL=	gamin-[0-9]*

post-patch:
	${REINPLACE_CMD} -e "s/-lstdc++//g" ${WRKSRC}/libfam/Makefile.am

pre-configure:
	${RM} -fr ${WRKSRC}/util
	${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am
	${CP} ${FILESDIR}/mntent* ${WRKSRC}/fam

.include <bsd.port.mk>
