# ex:ts=8
# New ports collection makefile for:	dia2code
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dia2code
PORTVERSION=	0.8.5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small utility used to generate code from a Dia diagram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		dia2code.1
PLIST_FILES=	bin/dia2code

post-install:
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
