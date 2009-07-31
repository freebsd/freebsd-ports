# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	1.4.2
PORTREVISION=	7
CATEGORIES=	databases kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/-//}
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	MySQL database server administration package for KDE

PLIST_FILES=	bin/mysqlnavigator
USE_MYSQL=	yes

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
MAKE_ENV+=	MOC="${MOC}" QTDIR="${QT_PREFIX}"

post-patch:
	@${REINPLACE_CMD} 's#-O2#${CXXFLAGS}#g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "*_moc.cpp" -exec ${RM} -f {} \;

pre-configure:
	@${REINPLACE_CMD} "s#-lqt#-lqt-mt ${PTHREAD_LIBS}#g" \
		${WRKSRC}/src/main/Makefile.in

.include <bsd.port.mk>
