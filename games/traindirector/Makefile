# New ports collection makefile for:	traindirector
# Date created:				09/08/2003
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	tdir
PORTVERSION=	1.18l
CATEGORIES=	games
MASTER_SITES=	http://xtsl.free.fr/118l/
DISTNAME=	traindir-${PORTVERSION}-src
WRKSRC=		${WRKDIR}/traindir-${PORTVERSION}

MAINTAINER=	mad@madpilot.net
COMMENT=	Train controller simulation

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes

post-extract:
.for file in Makefile field.c loadsave.c run.c setup_trdir.sh tgraph.c track.c track1.c trsim.c
	@${TR} -d '\015' < ${WRKSRC}/${file} > ${WRKDIR}/xxxx
	@${MV} ${WRKDIR}/xxxx ${WRKSRC}/${file}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's#PREFIX#${PREFIX}#' ${WRKSRC}/setup_trdir.sh

.include <bsd.port.mk>
