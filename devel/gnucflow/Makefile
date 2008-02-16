# New ports collection makefile for:	gnucflow
# Date created:		07 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gnucflow
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/cflow/
DISTNAME=	cflow-${PORTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Tool to chart control flow within the C program

CONFLICTS=	cflow-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INFO=		cflow

PLIST_FILES=	bin/cflow \
		share/locale/da/LC_MESSAGES/cflow.mo \
		share/locale/ga/LC_MESSAGES/cflow.mo \
		share/locale/pl/LC_MESSAGES/cflow.mo \
		share/locale/uk/LC_MESSAGES/cflow.mo \
		share/locale/vi/LC_MESSAGES/cflow.mo

.include <bsd.port.mk>
