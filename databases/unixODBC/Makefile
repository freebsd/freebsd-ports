# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.0.8
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-static --enable-shared
INSTALLS_SHLIB=	yes

.if defined(WITH_GUI)
USE_QT_VER=	2
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	MOC="${MOC}" LIBQT="-l${QTNAME}" \
		USER_INCLUDES="${QTCPPFLAGS}" \
		USER_LDFLAGS="${QTCFGLIBS}"
CONFIGURE_ARGS+=	--enable-gui \
			--with-qt-includes=${X11BASE}/include/qt2 \
			--with-qt-libraries=${X11BASE}/lib \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib
PLIST_SUB=	GUI:=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB=	GUI:="@comment "
.endif

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--enable-threads=yes
.else
CONFIGURE_ARGS+=	--enable-threads=no
.endif

pre-patch:
.if defined(WITH_PTHREAD)
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
			 s|-lqt|-lqt2-mt|g' ${WRKSRC}/configure
.else
	@${PERL} -pi -e 's|-lqt|-lqt2|g' ${WRKSRC}/configure
.endif

pre-build:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . \
		| ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
