# ex:ts=8
# New ports collection makefile for:	zipios
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	zipios++
PORTVERSION=	0.1.5.9
CATEGORIES=	archivers
MASTER_SITES=	http://http.us.debian.org/debian/pool/main/z/zipios++/
DISTNAME=	${PORTNAME}_${PORTVERSION}+cvs.2004.02.07.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A java.util.zip-like C++ library for reading and writing Zip files

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
# port don't strictly need it, but Wesnoth use it so must we
USE_GCC=	3.4
USE_REINPLACE=	yes
WANT_AUTOMAKE_VER=19

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}+cvs.2004.02.07

# tests need CppUnit
post-patch:
	@${REINPLACE_CMD} -e 's| tests||' ${WRKSRC}/Makefile.in

pre-configure:
.for i in install-sh missing depcomp mkinstalldirs
	@${RM} ${WRKSRC}/${i}
	@${CP} ${AUTOMAKE_DIR}/${i} ${WRKSRC}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/zipios++/zipios-config.h ${PREFIX}/include/zipios++/

.include <bsd.port.mk>
