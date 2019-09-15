# Created by: ijliao
# $FreeBSD$

PORTNAME=	genproto
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://freequaos.host.sk/genproto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates prototypes from C/C++ code

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

PLIST_FILES=	bin/genproto

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC," -e "s,^CFLAGS,#CFLAGS," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/genproto ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
