# ex:ts=8
# New ports collection makefile for:	libsndfile
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsndfile
PORTVERSION=	0.0.28
CATEGORIES=	audio
MASTER_SITES=	http://www.zip.com.au/~erikd/libsndfile/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-justsrc --disable-gcc-pipe
INSTALLS_SHLIB=	yes

PORTDOCS=	ChangeLog NEWS api.html bugs.html index.html libsndfile.jpg \
		new_file_type.HOWTO sndfile_info.html

pre-patch:
	@${REINPLACE_CMD} -e 's|-g -O2 ||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
