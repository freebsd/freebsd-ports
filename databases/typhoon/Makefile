# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	typhoon
PORTVERSION=	1.10.3
CATEGORIES=	databases
MASTER_SITES=	SUNSITE/libs/db
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Relational database library

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=	ddlp.1
MAN3=	d_close.3 d_crget.3 d_crread.3 d_crset.3 d_dbdpath.3 d_dbfpath.3 \
	d_dbget.3 d_dbset.3 d_delete.3 d_fillnew.3 d_getsequence.3 \
	d_keyfind.3 d_keyfrst.3 d_keylast.3 d_keynext.3 d_keyprev.3 \
	d_keyread.3 d_open.3 d_recfrst.3 d_reclast.3 d_recnext.3 d_recprev.3 \
	d_recread.3 d_recwrite.3 d_setfiles.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>| ; \
		 s|^void main|int main|' ${WRKSRC}/util/dbdview.c

post-install:
.for i in ${MAN1}
	(cd ${WRKSRC}/man && ${INSTALL_MAN} ${i} ${MAN1PREFIX}/man/man1)
.endfor
.for i in ${MAN3}
	(cd ${WRKSRC}/man && ${INSTALL_MAN} ${i} ${MAN3PREFIX}/man/man3)
.endfor
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/man && ${INSTALL_DATA} manual.asc ${DATADIR})
.for i in environ.h typhoon.h
	(cd ${WRKSRC}/include && ${INSTALL_DATA} ${i} ${PREFIX}/include)
.endfor

.include <bsd.port.mk>
