# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.1.1
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static --enable-shared
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
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
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
