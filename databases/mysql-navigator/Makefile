# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	databases kde
MASTER_SITES=	http://sql.kldp.org/snapshots/
DISTNAME=	mysqlnavigator-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	MySQL database server administration package for KDE

USE_MYSQL=	yes

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
CONFIGURE_TARGET=       --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	MOC="${MOC}" QTDIR="${X11BASE}"
MAKE_ENV+=	MOC="${MOC}" QTDIR="${X11BASE}"

post-patch:
	@${REINPLACE_CMD} 's#-O2#${CXXFLAGS}#g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "*_moc.cpp" -exec ${RM} -f {} \;

pre-configure:
	@${REINPLACE_CMD} "s#-lqt#-lqt-mt ${PTHREAD_LIBS}#g" \
		${WRKSRC}/src/main/Makefile.in

.include <bsd.port.mk>
