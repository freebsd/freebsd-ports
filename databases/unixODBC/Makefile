# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.0.7
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
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

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
			 s|-lqt|-lqt2|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's| -lc||g' ${WRKSRC}/ltmain.sh

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/unixODBC
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . \
		| ${TAR} -C ${PREFIX}/share/doc/unixODBC --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/unixODBC
.endif

.include <bsd.port.mk>
