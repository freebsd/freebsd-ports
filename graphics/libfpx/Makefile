# New ports collection makefile for:	fpx
# Date created:				Jan 10 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	fpx
PORTVERSION=	1.2.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wizards.dupont.com/pub/%SUBDIR%/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/%SUBDIR%/ \
		ftp://ftp.fifi.org/pub/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/pub/graphics/%SUBDIR%/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/%SUBDIR%/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/%SUBDIR%/
MASTER_SITE_SUBDIR=	ImageMagick/delegates

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/lib${DISTNAME}

post-patch:
	# Replacing references to <malloc.h> with <stdlib.h>
	# Ignore the /dev/stderr warning below. (What a hack!)
	${PERL} -pi -e 's/<malloc.h>/<stdlib.h>/' \
		`find ${WRKSRC} -type f | xargs ${GREP} -l '<malloc.h>'` /dev/stderr

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.mk>
