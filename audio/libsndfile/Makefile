# ex:ts=8
# New ports collection makefile for:	libsndfile
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsndfile
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.zip.com.au/~erikd/libsndfile/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-justsrc --disable-gcc-pipe
INSTALLS_SHLIB=	yes

MAN1=		sndfile-info.1 sndfile-play.1

PORTDOCS=	ChangeLog NEWS api.html bugs.html index.html libsndfile.jpg \
		new_file_type.HOWTO sndfile_info.html

pre-patch:
	@${REINPLACE_CMD} -e 's|-g -O2 ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|libdir[)]/pkgconfig|prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
