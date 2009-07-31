# New ports collection makefile for:	gdesklets
# Date created:				11 August 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets
PORTVERSION=	0.35.4
PORTREVISION=	6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gdesklets.de/files/ \
		${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/}
DISTNAME=	gDesklets-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A framework for Gnome 2.x for desktop applets

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop

INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack librsvg2 pygnomeextras

OPTIONS=	GDBM "install py-gdbm instead py-bsddb for config storage" off

MAN1=	gdesklets.1
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if defined(WITH_GDBM)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gdbm.so:${PORTSDIR}/databases/py-gdbm
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-install:
	@${MKDIR} ${PREFIX}/share/gdesklets/Displays
	@${MKDIR} ${PREFIX}/share/gdesklets/Sensors
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/lib/gdesklets
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
