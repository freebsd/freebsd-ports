# New ports collection makefile for:   qterm
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	qterm
PORTVERSION=	0.3.6
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gavin@FreeBSDChina.org
COMMENT=	QTerm is a BBS client in Unix

USE_QT_VER=	3
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-mt --with-pythondir=${LOCALBASE} --prefix=${PREFIX}

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	-2.3
.endif

.include <bsd.port.pre.mk>

pre-everything::
		@${ECHO_MSG} "Define WITHOUT_PYTHON to\
			disable PYTHON scripts support."

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/qterm/qtermtelnet.cpp
	@${REINPLACE_CMD} -e 's,-lssl,-lssl -lcrypto,' \
		${WRKSRC}/configure
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's,?"":,?QString::null:,' \
		${WRKSRC}/qterm/qtermconfig.cpp
.endif

.include <bsd.port.post.mk>
