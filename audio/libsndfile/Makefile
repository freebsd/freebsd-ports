# ex:ts=8
# New ports collection makefile for:	libsndfile
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsndfile
PORTVERSION=	1.0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--enable-justsrc --disable-gcc-pipe
INSTALLS_SHLIB=	yes

MAN1=		sndfile-convert.1 sndfile-info.1 sndfile-play.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
