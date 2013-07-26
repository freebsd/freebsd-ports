# ports collection makefile for:	unixcw
# Date created:		24 Dec 2007
# Whom:			Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	unixcw
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.ibiblio.org/pub/linux/apps/ham/morse/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Libs for cw on unix

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--includedir="${LOCALBASE}/include" \
			--libdir="${LOCALBASE}/lib"
MAN1=		cw.1 cwgen.1 cwcp.1
MAN3=		cwlib.3
.if defined(WITH_XCWCP)
BROKEN=		Depends on QT3 which is removed, update is in progress
MAN1+=		xcwcp.1
USE_QT_VER=	3
CONFIGURE_ARGS+=	QTLIB=qt-mt
PLIST_SUB+=	XCWCP=""
.else
PLIST_SUB+=	XCWCP="@comment "
.endif
MAN7=		cw.7 CW.7
MANCOMPRESSED=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
USE_GMAKE=	yes
AUTOTOOLSFILES=	configure.ac

pre-extract:
.if !defined(WITH_XCWCP)
	@${ECHO_CMD}
	@${ECHO_CMD} "****** To build xcwcp, interrupt the build  ******"
	@${ECHO_CMD} "****** now, set WITH_XCWCP and start again. ******"
	@${ECHO_CMD}
	@sleep 3
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LIBDATA%%|${PREFIX}/libdata|" \
	${WRKSRC}/src/cwlib/Makefile

.include <bsd.port.mk>
