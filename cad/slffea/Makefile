# ex:ts=8
# Ports collection makefile for:	slffea
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	slffea
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/SLFFEA/${PORTVERSION}
DISTNAME=	${PORTNAME}15
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	San Le's Free Finite Element Analysis

CONFLICTS=	swi-pl-[0-9]* TenDRA-[0-9]*

LICENSE=	GPLv2

USE_XORG=	xmu xt
USE_GL=		glut

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	everything
MAKE_JOBS_UNSAFE=	yes

EXEC=	beam/beam/bm beam/beam_gr/bmpost brick/brick/br \
	brick/brick_gr/brpost brick/brick_gr/pvbr \
	brick/brick_nl/nbr plate/plate/pl plate/plate_gr/plpost \
	quad/quad/qd quad/quad_gr/qdpost shell/shell/shl \
	shell/shell_gr/shpost shell/shell_gr/pvs truss/truss/ts \
	truss/truss_gr/tspost
PLIST_FILES=	${EXEC:T:S/^/bin\//}

post-patch:
	@(${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -E -e "s|^CC = .*|CC = ${CC} ${CFLAGS}|g" \
			-e "s|-lglut|-lglut ${PTHREAD_LIBS}|g" \
			-e "s|/usr/local|${LOCALBASE}|g" \
			-e "s|/usr/X/|${LOCALBASE}/|g" \
			-e "s|/usr/X11/|${LOCALBASE}/|g" \
			-e "s|/usr/X11R6/|${LOCALBASE}/|g")

do-install:
.for file in ${EXEC}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
