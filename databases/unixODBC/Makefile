# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.2.3
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	ODBC library suite for Unix

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-static --enable-shared \
		--with-libiconv-prefix=${LOCALBASE}
INSTALLS_SHLIB=	yes

.if defined(WITH_GUI)
USE_QT_VER=	2
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	MOC="${MOC}" \
		QTINC="${X11BASE}/include/qt2" \
		QTLIB="${X11BASE}/lib" \
		USER_INCLUDES="${QTCPPFLAGS}" \
		USER_LDFLAGS="${QTCFGLIBS}"
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB=	GUI:=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB=	GUI:="@comment "
.endif

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--enable-threads=yes
QT_NAME=		qt2-mt
.else
CONFIGURE_ARGS+=	--enable-threads=no
QT_NAME=		qt2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|"-lqt"|"-l${QT_NAME}"|g ; \
		 s|"-lqt-mt"|"-l${QT_NAME}"|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . \
		| ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
