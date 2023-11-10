PORTNAME=	sdts++
PORTVERSION=	1.5.1
PORTREVISION=	21
CATEGORIES=	devel
MASTER_SITES=	http://thor-f5.er.usgs.gov/sdts/sdtsxx/ \
		http://lychnobite.org/sdts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for SDTS related development
WWW=		https://mcmcweb.er.usgs.gov/sdts/sdtsxx/

DEPRECATED=	Last upstream release was in 2003 and both MASTER_SITES and WWW are unreachable
EXPIRATION_DATE=	2023-11-22

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		autoreconf bison dos2unix gmake libtool makeinfo
DOS2UNIX_GLOB=	*.cpp
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include

INSTALL_TARGET=	install-strip

INFO=		sdts++

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CPPFLAGS+=  -Dregister=
.endif

post-patch:
.for f in AUTHORS ChangeLog NEWS README
	@${TOUCH} ${WRKSRC}/sysutils/${f}
.endfor

.include <bsd.port.mk>
