# ex:ts=8
# New ports collection makefile for:	dia2code
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dia2code
PORTVERSION=	0.8.3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small utility used to generate code from a Dia diagram

USE_GNOME=	gnometarget libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

MAN1=		dia2code.1
PLIST_FILES=	bin/dia2code

post-patch:
	@${REINPLACE_CMD} -e '/<malloc.h>/d' ${WRKSRC}/dia2code/dia2code.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
