# New ports collection makefile for: typhoon
# Date created:		Wed Dec 11 15:16:19 CST 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	typhoon
PORTVERSION=	1.10.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/db
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A relational database library

HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

MAN1=	ddlp.1
MAN3=	d_close.3 d_crget.3 d_crread.3 d_crset.3 d_dbdpath.3 d_dbfpath.3 \
	d_dbget.3 d_dbset.3 d_delete.3 d_fillnew.3 d_getsequence.3 \
	d_keyfind.3 d_keyfrst.3 d_keylast.3 d_keynext.3 d_keyprev.3 \
	d_keyread.3 d_open.3 d_recfrst.3 d_reclast.3 d_recnext.3 d_recprev.3 \
	d_recread.3 d_recwrite.3 d_setfiles.3

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/util/dbdview.c

post-install:
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${PREFIX}/man/man3
.endfor
	@${MKDIR} ${PREFIX}/share/typhoon
	${INSTALL_DATA} ${WRKSRC}/man/manual.asc ${PREFIX}/share/typhoon
.for file in environ.h typhoon.h
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${PREFIX}/include
.endfor

.include <bsd.port.mk>
