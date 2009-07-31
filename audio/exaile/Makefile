# New ports collection makefile for:	exaile
# Date created:		19 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exaile
DISTVERSION=	0.2.14
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/ \
		http://wickedmachine.net/~jsa/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	AmaroK replacement for GTK+

RUN_DEPENDS=	py*-dbus>=0.82.1:${PORTSDIR}/devel/py-dbus \
		py*-notify>=0.1.1:${PORTSDIR}/devel/py-notify \
		py*-elementtree>=1.2.6:${PORTSDIR}/devel/py-elementtree \
		py*-mutagen>=1.11:${PORTSDIR}/audio/py-mutagen \
		py*-sexy>=0.1.9:${PORTSDIR}/x11-toolkits/py-sexy \
		py*-cddb>=1.4:${PORTSDIR}/audio/py-cddb \
		py*-pysqlite>=2.3.3:${PORTSDIR}/databases/py-pysqlite23

CONFLICTS=	exaile-0.2.99*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_GETTEXT=	yes
USE_GNOME=	pygtk2 pygnomeextras
USE_GSTREAMER=	python gnomevfs
USE_PYTHON=	yes
MAN1=	${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/createpot/d;s|/bin/echo|echo|;\
	s|$$[(]PREFIX[)]/share/exaile|${DATADIR}|;/install.*mmkeys/d;\
	s|$$[(]PREFIX[)]$$[(]LIBDIR[)]/exaile|${DATADIR}|;/mkdir.*LIBDIR/d;\
	s|$$[(]PREFIX[)]/share/man/man1|${MAN1PREFIX}/man/man1|'\
		${WRKSRC}/Makefile

.include <bsd.port.mk>
