# $FreeBSD$

PORTNAME=	gdesklets
PORTVERSION=	0.36.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GENTOO/distfiles
# XXX		currently broken: http://www.gdesklets.de/files/
DISTNAME=	gDesklets-${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A framework for Gnome 2.x for desktop applets

USE_BZIP2=	yes

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop

OPTIONS_DEFINE=	GDBM

WRKSRC=		${WRKDIR}/gDesklets-${PORTVERSION}

USE_GNOME=	gnomehack gnomeprefix intlhack librsvg2 pygnomeextras
USE_PYTHON=	yes
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDBM}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gdbm>0:${PORTSDIR}/databases/py-gdbm
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|`python -c|`$$PYTHON -c|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${DATADIR}/Displays
	@${TOUCH} ${DATADIR}/Displays/.keep_me
	@${MKDIR} ${DATADIR}/Sensors
	@${TOUCH} ${DATADIR}/Sensors/.keep_me
	@-update-mime-database ${PREFIX}/share/mime
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
