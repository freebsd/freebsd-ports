# New ports collection makefile for:	qfaxreader
# Date created:				2005-11-18
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#
# $Tecnik: ports/comms/qfaxreader/Makefile,v 1.4 2005/12/28 22:39:36 itetcu Exp $
#

PORTNAME=	qfaxreader
DISTVERSION=	0.3RC7
CATEGORIES=	comms graphics print
MASTER_SITES=	http://oss.thel.ro/${PORTNAME}/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Mono/color multipage tiff/fax files visualisation/printing utility

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QTDIR=${QT_PREFIX} PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}

MAN1=		qfaxreader.1

OPTIONS=	GDBM "For sender-id look-up (recomended)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GDBM) || exists(${LOCALBASE}/include/gdbm.h)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.endif

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

.include  <bsd.port.post.mk>
