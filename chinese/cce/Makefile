# New ports collection makefile for:   cce
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	cce
PORTVERSION=	0.36
CATEGORIES=	chinese
MASTER_SITES=	http://programmer.lib.sjtu.edu.cn/cce/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/cce/
DISTNAME=	${PORTNAME}-${PORTVERSION}-05052000

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cce-0.36_security.ukai-lin-fok.patch.gz
PATCH_DIST_ARGS=	-d ${WRKSRC} -p1

MAINTAINER=	statue@freebsd.sinica.edu.tw

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_REINPLACE=	yes
REINPLACE_ARGS=	# empty

MAN1=		cce.1

pre-configure:
	(cd ${WRKSRC} && ${LN} -fs Makefile.FreeBSD Makefile )

.include <bsd.port.pre.mk>
post-patch:
.if ${OSVERSION} > 500012
.for i in src/key.c src/main.c src/term.c src/vc.c src/vga.c
	${REINPLACE_CMD} "s,machine/console.h>,sys/consio.h>@#include <sys/fbio.h>@#include <sys/kbio.h>@," ${WRKSRC}/${i}| tr '@' '\n' > ${WRKSRC}/${i}.bakk && \
	${MV} ${WRKSRC}/${i}.bakk ${WRKSRC}/${i}
.endfor
.endif
.include <bsd.port.post.mk>
