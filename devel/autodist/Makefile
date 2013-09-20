# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	autodist
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://silcnet.org/download/autodist/sources/ \
		http://public.planetmirror.com/pub/silcnet/autodist/sources/ \
		ftp://ftp.planetmirror.com/pub/silcnet/autodist/sources/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Distribution creation system

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		autodist.1
INFO=		autodist

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-hook:/,/^$$/s/^	.*//' \
		${WRKSRC}/apps/autodist/Makefile.in
	${ECHO} "file empty" >> ${WRKSRC}/apps/autodist/doc/autodist.info

.include <bsd.port.post.mk>
