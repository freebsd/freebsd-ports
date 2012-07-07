# New ports collection makefile for:   recoll
# Date created:        5 December 2005
# Whom:                J.F. Dockes <jean-francois.dockes@wanadoo.fr>
#
# $FreeBSD$
#

PORTNAME=	recoll
PORTVERSION=	1.17.3
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal full text search package, based on Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	xapian:${PORTSDIR}/databases/xapian-core

OPTIONS_DEFINE=	QT4 ASPELL PYTHON X11MON
OPTIONS_DEFAULT=QT4 ASPELL PYTHON X11MON
ASPELL_DESC=	Enable ASpell support
X11MON_DESC=	Enable X11 session monitoring support

USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		recollindex.1
MAN5=		recoll.conf.5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	webkit moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}"
INSTALLS_ICONS=	yes
PLIST_SUB+=	QT=""
MAN1+=		recoll.1
.else
CONFIGURE_ARGS+=--disable-qtgui
PLIST_SUB+=	QT="@comment "
.endif

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.else
CONFIGURE_ARGS+=--without-aspell
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	Recoll-1.0-py${PYTHON_VER}.egg-info
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python-module
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MX11MON}
USE_XORG+=	ice sm x11
USE_FAM=	yes
CONFIGURE_ARGS+=--with-fam
.else
CONFIGURE_ARGS+=--disable-x11mon
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@QMAKE@|${TRUE}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib|${LOCALBASE}/lib|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|= -g -O2|=|' ${WRKSRC}/mk/localdefs.in
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/mk/${OPSYS}

post-configure:
.if ${PORT_OPTIONS:MQT4}
	@(cd ${WRKSRC}/qtgui && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})
.endif

.include <bsd.port.mk>
