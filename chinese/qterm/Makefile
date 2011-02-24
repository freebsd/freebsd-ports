# New ports collection makefile for:   qterm
# Date created:                10 Mar 2001
# Whom:                        Shen Chuan-Hsing
#
# $FreeBSD$
#

PORTNAME=	qterm
PORTVERSION=	0.4.1
PORTREVISION=	7
CATEGORIES=	chinese
MASTER_SITES=	 SF/qterm/qterm/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QTerm is a BBS client for BSD/Linux

USE_XORG=	x11 ice xext xt xaw xpm xi xproto xextproto
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_QT_VER=	3
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mt --prefix=${PREFIX}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	2.5+
CONFIGURE_ARGS+=	--with-pythondir=${LOCALBASE}
.endif

pre-everything::
.if !defined(WITHOUT_PYTHON)
	@${ECHO_MSG} "Define WITHOUT_PYTHON to disable Python scripts support."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,-lssl,-lssl -lcrypto,' \
		${WRKSRC}/configure

post-install:
	@${CHMOD} +w ${DATADIR}/qterm.cfg
	@${CHMOD} +w ${DATADIR}/address.cfg
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
