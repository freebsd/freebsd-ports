# New ports collection makefile for:	gdesklets
# Date created:				11 August 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets
PORTVERSION=	0.36.1
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gdesklets.de/files/ \
		GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A framework for Gnome 2.x for desktop applets

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop

OPTIONS=	GDBM "install py-gdbm instead py-bsddb for config storage" off

WRKSRC=		${WRKDIR}/gDesklets-${PORTVERSION}

USE_GNOME=	gnomehack gnomeprefix intlhack librsvg2 pygnomeextras
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITH_GDBM)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
.endif

post-install:
	@${MKDIR} ${DATADIR}/Displays
	@${TOUCH} ${DATADIR}/Displays/.keep_me
	@${MKDIR} ${DATADIR}/Sensors
	@${TOUCH} ${DATADIR}/Sensors/.keep_me
	@-update-mime-database ${PREFIX}/share/mime
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
