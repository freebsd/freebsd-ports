# ex:ts=8
# New ports collection makefile for:	HDF5
# Date created:			Jul 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.4.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-${PORTVERSION}/src/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Hierarchical Data Format library (from NCSA)

USE_REINPLACE=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure c++/configure
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-cxx --enable-production \
		--enable-threadsafe --disable-debug \
		--with-ssl --with-pthread
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[\$$]CFLAGS -pthread|\$$CFLAGS|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 s|[\$$]LDFLAGS -pthread|\$$LDFLAGS ${PTHREAD_LIBS}|g' \
			${WRKSRC}/config/freebsd
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/config/gnu-flags

post-install:
.for file in gif2h5 h52gif h5debug h5dump h5import h5ls h5perf h5repart
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
