# New ports collection makefile for:	guile
# Version required:	1.2
# Date created:		2 November 1997
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp $
#

DISTNAME=	guile-1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	YES
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
