# Created by: George Reid <greid@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rioutil
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to interface with the Rio600, Rio800, and psa[play devices

USES=		gmake
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		rioutil.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

EXTRA_PATCHES=  ${FILESDIR}/extra-patch-configure.ac
USE_AUTOTOOLS=	autoconf

post-extract:
#	@${RM} -f ${WRKSRC}/src/getopt*
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e 's,read_buffer = .*),(&),' \
		${WRKSRC}/librioutil/rio.c

.include <bsd.port.post.mk>
