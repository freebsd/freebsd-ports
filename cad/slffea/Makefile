# ex:ts=8
# Ports collection makefile for:	slffea
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	slffea
PORTVERSION=	1.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}13
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	San Le's Free Finite Element Analysis

CONFLICTS=	ploticus-* swi-pl-* TenDRA-*
USE_REINPLACE=	yes
USE_MESA=	yes
CFLAGS+=	-I${X11BASE}/include ${PTHREAD_CFLAGS}
WRKSRC=		${WRKDIR}/${PORTNAME}-1.3
ALL_TARGET=	everything
EXEC=	beam/beam/bm \
	beam/beam_gr/bmpost \
	brick/brick/br \
	brick/brick_gr/brpost \
	brick/brick_gr/pvbr \
	brick/brick_nl/nbr \
	plate/plate/pl \
	plate/plate_gr/plpost \
	quad/quad/qd \
	quad/quad_gr/qdpost \
	shell/shell/shl \
	shell/shell_gr/shpost \
	shell/shell_gr/pvs \
	truss/truss/ts \
	truss/truss_gr/tspost

post-patch:
	@(${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
	  ${REINPLACE_CMD} -E -e "s,^CC = (.*),CC = ${CC} ${CFLAGS},g ; \
	    s,-lglut,-lglut ${PTHREAD_LIBS},g")

do-install:
.for file in ${EXEC}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
