# Created by: pozar
# $FreeBSD$

PORTNAME=	tuneradio
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.lns.com/papers/tuneradio/ \
		http://cvsup1.theplanet.com/distfiles/

MAINTAINER=	pozar@lns.com
COMMENT=	Command line method of tuning a Brooktree FM tuner card

.if !exists(/usr/include/dev/bktr/ioctl_bt848.h)
IGNORE=	needs bktr(4) which is no longer available on your FreeBSD version
.endif

PLIST_FILES=	bin/tuneradio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tuneradio ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
