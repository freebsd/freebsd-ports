# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	autodist
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://silcnet.org/download/autodist/sources/ \
		http://public.planetmirror.com/pub/silcnet/autodist/sources/ \
		ftp://ftp.planetmirror.com/pub/silcnet/autodist/sources/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Distribution creation system

BROKEN=		unfetchable

GNU_CONFIGURE=	yes

INFO=		autodist

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-hook:/,/^$$/s/^	.*//' \
		${WRKSRC}/apps/autodist/Makefile.in
	${ECHO} "file empty" >> ${WRKSRC}/apps/autodist/doc/autodist.info

.include <bsd.port.mk>
