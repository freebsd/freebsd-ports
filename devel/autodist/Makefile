# New ports collection makefile for:	autodist
# Date created:		2007-02-21
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	autodist
PORTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	http://silcnet.org/download/autodist/sources/ \
		http://public.planetmirror.com/pub/silcnet/autodist/sources/ \
		ftp://ftp.planetmirror.com/pub/silcnet/autodist/sources/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Distribution creation system

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--infodir=${PREFIX}/${INFO_PATH} --mandir=${MANPREFIX}/man
USE_GMAKE=	yes

MAN1=		autodist.1
INFO=		autodist

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^install-exec-hook:/,/^$$/s/^	.*//' \
		${WRKSRC}/apps/autodist/Makefile.in

.include <bsd.port.post.mk>
