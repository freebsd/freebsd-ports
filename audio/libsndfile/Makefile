# ex:ts=8
# New ports collection makefile for:	libsndfile
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsndfile
PORTVERSION=	1.0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.zip.com.au/~erikd/libsndfile/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-justsrc --disable-gcc-pipe
INSTALLS_SHLIB=	yes

MAN1=		sndfile-convert.1 sndfile-info.1 sndfile-play.1

MYPORTDOCS=	ChangeLog NEWS api.html bugs.html index.html libsndfile.jpg \
		new_file_type.HOWTO sndfile_info.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
