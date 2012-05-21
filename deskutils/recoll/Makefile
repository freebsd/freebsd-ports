# New ports collection makefile for:   recoll
# Date created:        5 December 2005
# Whom:                J.F. Dockes <jean-francois.dockes@wanadoo.fr>
#
# $FreeBSD$
#

PORTNAME=	recoll
PORTVERSION=	1.17.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal full text search package, based on Xapian

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	xapian.26:${PORTSDIR}/databases/xapian-core

OPTIONS=	QT "Enable Qt-based GUI support" on \
		ASPELL "Enable ASpell support" on \
		PYTHON "Enable Python module support" on \
		X11MON "Enable X11 session monitoring support" on

USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		recollindex.1
MAN5=		recoll.conf.5

.include <bsd.port.options.mk>

.if defined(WITHOUT_QT)
CONFIGURE_ARGS+=--disable-qtgui
PLIST_SUB+=	QT="@comment "
.else
USE_QT_VER=	4
QT_COMPONENTS=	webkit moc_build qmake_build rcc_build uic_build
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}" QMAKE="${QMAKE}"
INSTALLS_ICONS=	yes
PLIST_SUB+=	QT=""
MAN1+=		recoll.1
.endif

.if defined(WITHOUT_ASPELL)
CONFIGURE_ARGS+=--without-aspell
.else
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

.if defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=--disable-python-module
PLIST_SUB+=	PYTHON="@comment "
.else
USE_PYTHON=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_EGGINFO=	Recoll-1.0-py${PYTHON_VER}.egg-info
PLIST_SUB+=	PYTHON=""
.endif

.if defined(WITHOUT_X11MON)
CONFIGURE_ARGS+=--disable-x11mon
.else
USE_XORG+=	ice sm x11
USE_FAM=	yes
CONFIGURE_ARGS+=--with-fam
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@QMAKE@|${TRUE}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/local/lib|${LOCALBASE}/lib|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/--prefix=/s|^|@NOPYTHON@|' ${WRKSRC}/recollinstall.in
	@${REINPLACE_CMD} -e \
		's|= -g -O2|=|' ${WRKSRC}/mk/localdefs.in
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/mk/${OPSYS}

post-configure:
.if !defined(WITHOUT_QT)
	@(cd ${WRKSRC}/qtgui && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})
.endif

.include <bsd.port.mk>
