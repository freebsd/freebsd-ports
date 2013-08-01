# $FreeBSD$

PORTNAME=	wy60
PORTVERSION=	2.0.9
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Curses-based emulator for the Wyse 60 terminal

GNU_CONFIGURE=	yes

MAKE_ARGS=	etc_DATA=wy60.rc.sample

MAN1=		wy60.1

pre-build:
	@${CP} ${WRKSRC}/wy60.rc ${WRKSRC}/wy60.rc.sample

post-install:
	if test ! -f ${PREFIX}/etc/wy60.rc; then \
		${CP} -p ${PREFIX}/etc/wy60.rc.sample ${PREFIX}/etc/wy60.rc; \
	fi

.include <bsd.port.mk>
