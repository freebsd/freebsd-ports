# New ports collection makefile for:	fb
# Date created:				Oct 15, 1999
# Whom:					Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	fb
PORTVERSION=	1.5
CATEGORIES=	editors
MASTER_SITES=	http://home.mho.net/jswaby/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Binary File Viewer, Editor, & Manipulator (and a lot more)

NO_WRKSUBDIR=	Yes

MAN1=		fb.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/fb
MAKEFILE=	${FILESDIR}/Makefile.in
MAKE_ARGS+=	PREFIX="${PREFIX}"

.include <bsd.port.mk>
