# New ports collection makefile for:   xawtv
# Date created:        03 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       xawtv
PORTVERSION=	3.67
CATEGORIES=     graphics
MASTER_SITES=   http://bytesex.org/xawtv/
DISTNAME=	${PORTNAME}_${PORTVERSION}
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

CONFIGURE_ARGS=	--prefix=${PREFIX}


GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes


FILES_CFLAGS=	. font i2c man src radio webcam oldstuff/vtx \
		libng libvbi http
FILES_X11BASE=	configure Make.config.in


MAN1=		alevtd.1 dump-mixers.1 fbtv.1 motv.1 ntsc-cc.1 propwatch.1 record.1 \
		rootv.1 scantv.1 showriff.1 \
		streamer.1 subtitles.1 ttv.1 v4lctl.1 \
		webcam.1 xawtv-remote.1 xawtv.1
MAN5=		xawtvrc.5
MAN8=		v4l-conf.8

PLIST_SUB+=	X11PREFIX=${X11BASE}
STRCASESTRFILES=src/commands.c

post-patch:
.for i in ${FILES_X11BASE}
	${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/$i
.endfor
.for i in ${STRCASESTRFILES}
	${PERL} -pi -e "s|strcasestr|mystrcasestr|g" ${WRKSRC}/$i
.endfor

post-configure:
.for i in ${FILES_CFLAGS}
	${PERL} -pi -e "s|^CFLAGS=|CFLAGS+=|g" ${WRKSRC}/$i/Makefile
.endfor

.include <bsd.port.mk>
