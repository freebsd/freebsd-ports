# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	fam
PORTVERSION=	2.6.10
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	ftp://oss.sgi.com/projects/fam/download/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File alteration monitor

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/fam/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/libfam/COPYING

CFLAGS+=	-Wno-deprecated

USES=		autoreconf cpe gmake libtool
CPE_VENDOR=	sgi
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message

#CONFLICTS_INSTALL=	gamin-[0-9]*

post-patch:
	${REINPLACE_CMD} -e "s/-lstdc++//g" ${WRKSRC}/libfam/Makefile.am

pre-configure:
	${RM} -r ${WRKSRC}/util
	${MV} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.orig
	${SED} -e s/util// -e /SUBDIRS/q \
		<${WRKSRC}/Makefile.am.orig >${WRKSRC}/Makefile.am
	${CP} ${FILESDIR}/mntent* ${WRKSRC}/fam

.include <bsd.port.mk>
