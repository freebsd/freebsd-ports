# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libopensync
PORTVERSION=	0.22
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	022

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freedesktop synchronization framework

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

SWIG_LANGUAGES=	python
GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig python tar:bzip2
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

CONFLICTS=	libopensync-0.[3-9]*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} ${REINPLACE_CMD} \
	    -e 's|-Werror||g'
	@${REINPLACE_CMD} -e 's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e "s,echo aout, echo elf,g" ${WRKSRC}/configure

.include <bsd.port.mk>
