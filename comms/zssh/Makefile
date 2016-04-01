# Created by: Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
# $FreeBSD$

PORTNAME=	zssh
PORTVERSION=	1.5c
CATEGORIES=	comms security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactively transferring files to a remote machine while using ssh

RUN_DEPENDS=	lrz:comms/lrzsz

HAS_CONFIGURE=	yes
USES=		readline tar:tgz

PLIST_FILES=	bin/zssh bin/ztelnet man/man1/zssh.1.gz man/man1/ztelnet.1.gz

post-configure:
	@${REINPLACE_CMD} -e 's,^prefix.*,prefix = ${PREFIX},g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
