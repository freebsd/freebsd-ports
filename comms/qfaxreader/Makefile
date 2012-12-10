# New ports collection makefile for:	qfaxreader
# Date created:				2005-11-18
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#
# $Tecnik: ports/comms/qfaxreader/Makefile,v 1.4 2005/12/28 22:39:36 itetcu Exp $
#

PORTNAME=	qfaxreader
DISTVERSION=	0.3.1
PORTREVISION=	7
CATEGORIES=	comms graphics print
MASTER_SITES=	SF

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Mono/color multipage tiff/fax files visualisation/printing utility

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
MAKE_JOBS_UNSAFE=	yes

MAN1=		qfaxreader.1
MANCOMPRESSED=	yes

OPTIONS_DEFINE=	GDBM
GDBM_DESC=	For sender-id look-up (recomended)
OPTIONS_DEFAULT=GDBM

DEPRECATED=	No activity upstream since 2006; uses QT3
EXPIRATION_DATE=	2013-06-30

.include <bsd.port.pre.mk>

#.if !defined(WITHOUT_GDBM) || exists(${LOCALBASE}/include/gdbm.h)
.if ${PORT_OPTIONS:MGDBM) || exists(${LOCALBASE}/include/gdbm.h)
LIB_DEPENDS+=	gdbm.4:${PORTSDIR}/databases/gdbm
.endif

.include  <bsd.port.post.mk>
