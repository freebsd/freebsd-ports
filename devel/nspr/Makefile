# Ports collection Makefile for:	nspr
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nspr
PORTVERSION=	4.4.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	nspr/releases/v${PORTVERSION}/src

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A platform-neutral API for system level and libc like functions

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/nsprpub/build

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--disable-debug \
		--with-pthreads
CONFIGURE_ENV=	BSD_PTHREAD_LIBS=${PTHREAD_LIBS}
MAKE_ENV=	DIST=${WRKSRC}/dist

LIBS=		libnspr4.so.1 libplc4.so.1 libplds4.so.1

do-install:
	${MKDIR} ${PREFIX}/include/nspr
	${TAR} -C ${WRKSRC}/dist/include --dereference -cf - . | \
		${TAR} -C ${PREFIX}/include -xf -
	${TAR} -C ${WRKSRC}/dist/lib --dereference -cf - . | \
		${TAR} -C ${PREFIX}/lib -xf -
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin
.for lib in ${LIBS}
	${LN} -sf ${lib} ${PREFIX}/lib/${lib:S/.1$//}
.endfor

.include <bsd.port.mk>
