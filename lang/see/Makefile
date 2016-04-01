# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	see
PORTVERSION=	3.1.1424
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://download.openpkg.org/components/cache/see/ \
		http://lil.fr.distfiles.macports.org/see/ \
		ftp://ftp.mirrorservice.org/sites/distfiles.macports.org/see/ \
		ftp://mirror.csclub.uwaterloo.ca/MacPorts/mpdistfiles/see/

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Simple ECMAScript Engine (SEE)

LICENSE=	BSD

OPTIONS_DEFINE=	GC DEBUG DOCS
OPTIONS_DEFAULT=	GC
GC_DESC=	Use Boehm-Weiser garbage collection package
DEBUG_DESC=	Internal SEE library debugging

CONFLICTS=	see-devel-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_LDCONFIG=	yes
USES=		libtool pathfix perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-O3
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

DEBUG_CFLAGS_OFF=	-DNDEBUG
GC_LIB_DEPENDS=		libgc.so:devel/boehm-gc
GC_CONFIGURE_WITH=	boehm-gc

post-patch:
	@${REINPLACE_CMD} -e "s|PACKAGE_BUGREPORT='leonard@users|PACKAGE_BUGREPORT='leonard\\\@users|" \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in doc/USAGE.html AUTHORS NEWS README TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
