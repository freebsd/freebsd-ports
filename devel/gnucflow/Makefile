# New ports collection makefile for:	gnucflow
# Date created:		07 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gnucflow
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/cflow/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to chart control flow within the C program

CONFLICTS=	cflow-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

INFO=		cflow

PLIST_FILES=	bin/cflow


.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix="${LOCALBASE}"
PLIST_FILES+= 	share/locale/da/LC_MESSAGES/cflow.mo \
		share/locale/ga/LC_MESSAGES/cflow.mo \
		share/locale/id/LC_MESSAGES/cflow.mo \
		share/locale/pl/LC_MESSAGES/cflow.mo \
		share/locale/uk/LC_MESSAGES/cflow.mo \
		share/locale/vi/LC_MESSAGES/cflow.mo \
		share/locale/zh_CN/LC_MESSAGES/cflow.mo
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.mk>
