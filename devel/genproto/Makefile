# Created by: ijliao
# $FreeBSD$

PORTNAME=	genproto
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://freequaos.host.sk/genproto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates prototypes from C/C++ code

PLIST_FILES=	bin/genproto

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC," -e "s,^CFLAGS,#CFLAGS," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/genproto ${PREFIX}/bin

.include <bsd.port.mk>
