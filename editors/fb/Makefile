# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	fb
PORTVERSION=	1.5
CATEGORIES=	editors
MASTER_SITES=	http://home.mho.net/jswaby/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Binary file viewer, editor, and manipulator (and a lot more)

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
NO_WRKSUBDIR=	Yes

PLIST_FILES=	bin/fb \
		man/man1/fb.1.gz
USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.in
MAKE_ARGS+=	PREFIX="${PREFIX}"

.include <bsd.port.mk>
