# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.14f
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://freebsd.sinica.edu.tw/~statue/ \
		ftp://ftp.gnuchina.org/pub/linux/chinese/inputmethod/console/zhcon/BSDPort/

MAINTAINER=	statue@freebsd.sinica.edu.tw

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		zhcon.1

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 500012
post-patch:
	@${PERL} -pi -e 's,machine/console.h>,sys/consio.h>\n#include <sys/fbio.h>\n#include <sys/kbio.h>\n,' ${WRKSRC}/${PORTNAME}/*.cpp
.endif
.include <bsd.port.post.mk>
