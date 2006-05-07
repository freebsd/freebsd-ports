# New ports collection makefile for:	cal3d
# Date created:				12 Jul 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	cal3d
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-full-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Skeletal based 3d character animation library written in C++

CONFLICTS=	cal3d-devel-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	automake:19 autoheader:259 libtool:15
AUTOMAKE_ARGS=	"--add-missing"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^all_libraries/d' ${WRKSRC}/src/cal3d/Makefile.am

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${LIBTOOLIZE} --automake --force

# XXX: handle slight differences between 6.x and 5.x/4.x
post-install:
	@${RM} -f ${PREFIX}/lib/libcal3d.a

.include <bsd.port.post.mk>
