# New ports collection makefile for:   qterm
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	qterm
PORTVERSION=	0.3.7
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gavin@FreeBSDChina.org
COMMENT=	QTerm is a BBS client in Unix

USE_QT_VER=	3
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--enable-mt --prefix=${PREFIX}

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	-2.3
CONFIGURE_ARGS+=	--with-pythondir=${LOCALBASE}
.endif

pre-everything::
.if !defined(WITHOUT_PYTHON)
	@${ECHO_MSG} "Define WITHOUT_PYTHON to disable Python scripts support."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,-lssl,-lssl -lcrypto,' \
		${WRKSRC}/configure

.include <bsd.port.mk>
