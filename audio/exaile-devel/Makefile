# New ports collection makefile for:	exaile
# Date created:		19 December 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	exaile
DISTVERSION=	0.2.99.1
CATEGORIES=	audio
MASTER_SITES=	http://www.exaile.org/files/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}_0.3.0a1

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	AmaroK replacement for GTK+ (developmental series)

RUN_DEPENDS=	py*-dbus>=0.82.1:${PORTSDIR}/devel/py-dbus \
		py*-notify>=0.1.1:${PORTSDIR}/devel/py-notify \
		py*-elementtree>=1.2.6:${PORTSDIR}/devel/py-elementtree \
		py*-mutagen>=1.11:${PORTSDIR}/audio/py-mutagen \
		py*-sexy>=0.1.9:${PORTSDIR}/x11-toolkits/py-sexy \
		py*-cddb>=1.4:${PORTSDIR}/audio/py-cddb

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_GNOME=	pygtk2 pygnomeextras
USE_GSTREAMER=	python gnomevfs
USE_PYTHON=	2.5+

CONFLICTS=	exaile-0.2.[0-9][0-8]* exaile-0.3.*

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
PLIST_SUB+=		NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/createpot/d;s|/bin/echo|echo|;\
	s|$$[(]PREFIX[)]/share/exaile|${DATADIR}|;/install.*mmkeys/d;\
	s|$$[(]PREFIX[)]$$[(]LIBDIR[)]/exaile|${DATADIR}|;/mkdir.*LIBDIR/d;\
	s|$$[(]PREFIX[)]/share/man/man1|${MAN1PREFIX}/man/man1|'\
		${WRKSRC}/Makefile
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|exaile\.mo|SKIP_NLS_HACK|' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
