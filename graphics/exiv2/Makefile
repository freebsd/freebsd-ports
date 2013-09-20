# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
PORTVERSION=	0.23
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif and Iptc metadata manipulation library and tools

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
USES=		gettext
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAN1=		exiv2.1
ALLTARGET=	all
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
