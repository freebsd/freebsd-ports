# New ports collection makefile for:	fpx
# Date created:				Jan 10 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libfpx
PORTVERSION=	1.2.0.9
CATEGORIES=	graphics
MASTER_SITES=	ftp://gd.tuwien.ac.at/pub/graphics/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/multimedia/graphics/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/ImageMagick,} \
		ftp://ftp.crc.ca/pub/packages/graphics/imagemagick/ \
		ftp://ftp.imagemagick.org/pub/%SUBDIR%/ \
		ftp://ftp.planetmirror.com/pub/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/%SUBDIR%/ \
		ftp://zoffy.asahi-net.or.jp/pub/graphics/%SUBDIR%/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/%SUBDIR%/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/graphics/%SUBDIR%/ \
		ftp://ftp.kddlabs.co.jp/graphics/%SUBDIR%/ \
		ftp://ftp.icm.edu.pl/pub/graphics/%SUBDIR%/ \
		ftp://giswitch.sggw.waw.pl/pub/graphics/%SUBDIR%/ \
		ftp://ftp.fifi.org/pub/%SUBDIR%/ \
		ftp://ftp.simplesystems.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	ImageMagick/delegates

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library routines for working with Flashpix images

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg
MAKE_ARGS+=	-j2
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

post-patch:
	# Replacing references to <malloc.h> with <stdlib.h>
	# Ignore the /dev/stderr warning below. (What a hack!)
	${REINPLACE_CMD} -e 's,<malloc\.h>,<stdlib\.h>,' \
		${WRKSRC}/oless/h/ref.hxx ${WRKSRC}/oless/h/vect.hxx

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.post.mk>
