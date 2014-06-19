# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	msynctool
PORTVERSION=	0.22
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	webmaster@kibab.com
COMMENT=	Command line client for the OpenSync framework

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022

CONFLICTS=	osynctool-[0-9]*

USES=		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/convtest \
		bin/convcard \
		bin/${PORTNAME} \
		man/man1/convcard.1.gz \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
