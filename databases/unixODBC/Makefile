# New ports collection makefile for:    unixODBC
# Date created:         May 11, 2000
# Whom:                 Nick Sayer <nsayer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unixODBC
PORTVERSION=	2.0.5
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	ports@FreeBSD.org

USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--include-deps
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-static --enable-shared
INSTALLS_SHLIB=	yes

.if defined(WITH_GUI)
USE_QT2=	yes
CONFIGURE_ENV=	MOC="${X11BASE}/bin/moc2"
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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/unixODBC
	${TAR} -C ${WRKSRC}/doc --exclude '*Makefile*' -cf - . \
		| ${TAR} -C ${PREFIX}/share/doc/unixODBC --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/unixODBC
.endif

.include <bsd.port.mk>
