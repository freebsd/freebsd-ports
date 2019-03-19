# Created by: ajk@waterspout.com
# $FreeBSD$

PORTNAME=	msrc0
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://www.komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Meta source fake-out script for building ksb tools

DEPRECATED=	No longer required as comms/conserver is being retired.
EXPIRATION_DATE=	2019-03-31

USES=		tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/makeme
WRKSRC=		${WRKDIR}/${PORTNAME}-0.6

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makeme ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
