# New ports collection makefile for:	fpx
# Date created:				Jan 10 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	fpx
PORTVERSION=	1.2.0-3
CATEGORIES=	graphics
MASTER_SITES=	http://imagemagick.sourceforge.net/http/delegates/ \
		ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/pub/graphics/%SUBDIR%/ \
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

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/lib${DISTNAME:C/-[^-]*$//}

post-patch:
	# Replacing references to <malloc.h> with <stdlib.h>
	# Ignore the /dev/stderr warning below. (What a hack!)
	${PERL} -pi -e 's/<malloc.h>/<stdlib.h>/' \
		`find ${WRKSRC} -type f | xargs ${GREP} -l '<malloc.h>'` /dev/stderr

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.mk>
